
// DoctorAppointmentDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "DoctorAppointment.h"
#include "DoctorAppointmentDlg.h"
#include "CLoginDlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDoctorAppointmentDlg dialog



CDoctorAppointmentDlg::CDoctorAppointmentDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_DOCTORAPPOINTMENT, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDoctorAppointmentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_USERNAME_LOGEDIN, m_static_logedin_username);
	DDX_Control(pDX, IDC_STATIC_USERLOGEDIN_EMAIL, m_static_logedin_useremail);
	DDX_Control(pDX, IDC_EDIT_SEARCHFIELD, m_edit_searchfield);
}

BEGIN_MESSAGE_MAP(CDoctorAppointmentDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BTTN_SEARCH, &CDoctorAppointmentDlg::OnBnClickedBttnSearch)
	ON_BN_CLICKED(IDC_BTTN_LOGOUT, &CDoctorAppointmentDlg::OnBnClickedBttnLogout)
	ON_BN_CLICKED(IDC_BUTTON_DASHBOARD, &CDoctorAppointmentDlg::OnBnClickedButtonDashboard)
	ON_BN_CLICKED(IDC_BUTTON_DOCTORS, &CDoctorAppointmentDlg::OnBnClickedButtonDoctors)
	ON_BN_CLICKED(IDC_BUTTON_SCHEDULE, &CDoctorAppointmentDlg::OnBnClickedButtonSchedule)
	ON_BN_CLICKED(IDC_BUTTON_APPOINTMENT, &CDoctorAppointmentDlg::OnBnClickedButtonAppointment)
	ON_BN_CLICKED(IDC_BUTTON_PATIENT, &CDoctorAppointmentDlg::OnBnClickedButtonPatient)
END_MESSAGE_MAP()


// CDoctorAppointmentDlg message handlers

BOOL CDoctorAppointmentDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	//Customize font to display logedin user name.
	font.CreateFont(
		20,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_BOLD,                   // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		_T("Arial"));                 // lpszFacename

	CString struserrole = user.GetUserrole();
	GetDlgItem(IDC_STATIC_USERNAME_LOGEDIN)->SetWindowTextW(struserrole);
	GetDlgItem(IDC_STATIC_USERNAME_LOGEDIN)->SetFont(&font);

	CString strusername = user.GetUsername();
	GetDlgItem(IDC_STATIC_USERLOGEDIN_EMAIL)->SetWindowTextW(strusername);

	CTime t = CTime::GetCurrentTime();
	GetDlgItem(IDC_STATIC_DATE)->SetWindowTextW(t.Format("%d-%m-%Y"));

	//============================================================

	m_TabDashboard.Create(IDD_TAB_DASHBOARD, this);
	m_TabDashboard.SetWindowPos(this, 195,100, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	m_TabDashboard.SetDatabaseConnect(dbconnect);
	m_TabDashboard.ShowWindow(SW_SHOW);

	m_TabDoctors.Create(IDD_TAB_DOCTORS, this);
	m_TabDoctors.SetWindowPos(this, 195, 100, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	m_TabDoctors.SetDatabaseConnect(dbconnect);
	m_TabDoctors.UpdateListCtrl();

	m_TabSchedule.Create(IDD_TAB_SCHEDULE, this);
	m_TabSchedule.SetWindowPos(this, 195, 100, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	m_TabAppointment.Create(IDD_TAB_APPOINTMENT, this);
	m_TabAppointment.SetWindowPos(this, 195, 100, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	
	m_TabPatient.Create(IDD_TAB_PATIENT, this);
	m_TabPatient.SetWindowPos(this, 195, 100, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	m_TabPatient.SetDatabaseConnect(dbconnect);
	m_TabPatient.UpdateListCtrl();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDoctorAppointmentDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDoctorAppointmentDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		/*CLoginDlg dlg;
		dlg.DoModal();*/
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDoctorAppointmentDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CDoctorAppointmentDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(255, 255, 255));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;
}


void CDoctorAppointmentDlg::DisableTabDialog()
{
	//Disable all Tab Dialog.
	m_TabDashboard.ShowWindow(SW_HIDE);
	m_TabDoctors.ShowWindow(SW_HIDE);
	m_TabSchedule.ShowWindow(SW_HIDE);
	m_TabAppointment.ShowWindow(SW_HIDE);
	m_TabPatient.ShowWindow(SW_HIDE);
}


void CDoctorAppointmentDlg::OnBnClickedBttnSearch()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox(_T("TODO: Add your control notification handler code here"));
}


void CDoctorAppointmentDlg::OnBnClickedBttnLogout()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox(_T("Dummy Logout successfully."));
}

void CDoctorAppointmentDlg::OnBnClickedButtonDashboard()
{
	// TODO: Add your control notification handler code here
	m_TabDashboard.ShowWindow(SW_SHOW);
	m_TabDoctors.ShowWindow(SW_HIDE);
	m_TabSchedule.ShowWindow(SW_HIDE);
	m_TabAppointment.ShowWindow(SW_HIDE);
	m_TabPatient.ShowWindow(SW_HIDE);
}


void CDoctorAppointmentDlg::OnBnClickedButtonDoctors()
{
	// TODO: Add your control notification handler code here
	m_TabDoctors.ShowWindow(SW_SHOW);
	m_TabDashboard.ShowWindow(SW_HIDE);
	m_TabSchedule.ShowWindow(SW_HIDE);
	m_TabAppointment.ShowWindow(SW_HIDE);
	m_TabPatient.ShowWindow(SW_HIDE);
}


void CDoctorAppointmentDlg::OnBnClickedButtonSchedule()
{
	// TODO: Add your control notification handler code here
	m_TabSchedule.ShowWindow(SW_SHOW);
	m_TabDashboard.ShowWindow(SW_HIDE);
	m_TabDoctors.ShowWindow(SW_HIDE);
	m_TabAppointment.ShowWindow(SW_HIDE);
	m_TabPatient.ShowWindow(SW_HIDE);
}


void CDoctorAppointmentDlg::OnBnClickedButtonAppointment()
{
	// TODO: Add your control notification handler code here
	m_TabAppointment.ShowWindow(SW_SHOW);
	m_TabDashboard.ShowWindow(SW_HIDE);
	m_TabDoctors.ShowWindow(SW_HIDE);
	m_TabSchedule.ShowWindow(SW_HIDE);
	m_TabPatient.ShowWindow(SW_HIDE);
}


void CDoctorAppointmentDlg::OnBnClickedButtonPatient()
{
	// TODO: Add your control notification handler code here
	m_TabPatient.ShowWindow(SW_SHOW);
	m_TabDashboard.ShowWindow(SW_HIDE);
	m_TabDoctors.ShowWindow(SW_HIDE);
	m_TabSchedule.ShowWindow(SW_HIDE);
	m_TabAppointment.ShowWindow(SW_HIDE);
}
