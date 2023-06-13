// CLoginDlg.cpp : implementation file
//

#include "pch.h"
#include "DoctorAppointment.h"
#include "afxdialogex.h"
#include "CLoginDlg.h"
#include "CUserLogin.h"


// CLoginDlg dialog

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_LOGIN, pParent)
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_USERROLE, m_combo_userrole);
	DDX_Control(pDX, IDC_EDIT_USERNAME, m_edit_username);
	DDX_Control(pDX, IDC_EDIT_USERPASSWRD, m_edit_userpassword);
	DDX_Control(pDX, IDC_MFCBUTTON_LOGIN, m_MFCBttn_Login);
	DDX_Control(pDX, IDC_MFCBUTTON_CANCLE, m_MFCBttn_Cancle);
}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Customize Welcome text font and size 
	CFont font;
	font.CreateFont(
		50,                        // nHeight
		30,                         // nWidth
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

	GetDlgItem(IDC_STATIC_WELCOMETEXT)->SetFont(&font);

	// Color Login  and Cancel Button
	m_MFCBttn_Login.m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;   //required for flatering and use bg color
	m_MFCBttn_Login.m_bTransparent = false;                             //reg for use bg color
	m_MFCBttn_Login.SetFaceColor(RGB(0, 0, 255), true);                 // Button Color Blue
	m_MFCBttn_Login.SetTextColor(RGB(255, 255, 255));                   // Button text color White

	m_MFCBttn_Cancle.m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;   //required for flatering and use bg color
	m_MFCBttn_Cancle.m_bTransparent = false;                             //reg for use bg color
	m_MFCBttn_Cancle.SetFaceColor(RGB(255, 0, 255), true);               // Button Color Blue
	m_MFCBttn_Cancle.SetTextColor(RGB(255, 255, 255));                   // Button text color White


	m_combo_userrole.AddString(_T("Admin"));
	m_combo_userrole.AddString(_T("User"));
	m_combo_userrole.AddString(_T("Doctor"));

	m_combo_userrole.SelectString(0, _T("Admin"));

	return TRUE;
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_USERROLE, &CLoginDlg::OnCbnSelchangeComboUserrole)
	ON_BN_CLICKED(IDC_MFCBUTTON_LOGIN, &CLoginDlg::OnBnClickedMfcbuttonLogin)
	ON_BN_CLICKED(IDC_MFCBUTTON_CANCLE, &CLoginDlg::OnBnClickedMfcbuttonCancle)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CLoginDlg message handlers


void CLoginDlg::OnCbnSelchangeComboUserrole()
{
	// TODO: Add your control notification handler code here
}


void CLoginDlg::OnBnClickedMfcbuttonLogin()
{
	// TODO: Add your control notification handler code here
	CString strUserRole;
	CString strUserName;
	CString strUserPassword;
	CUserLogin ulogin;
	
	CComboBox* pCComboBoxUserRole = (CComboBox*)GetDlgItem(IDC_COMBO_USERROLE);
	if (pCComboBoxUserRole != nullptr)
	{
		pCComboBoxUserRole->GetWindowTextW(strUserRole);
	}

	CEdit* pCEditUserName = (CEdit*)GetDlgItem(IDC_EDIT_USERNAME);
	if (pCEditUserName != nullptr)
	{
		pCEditUserName->GetWindowTextW(strUserName);
		if (strUserName.IsEmpty())
		{
			AfxMessageBox(_T("user Name can not be empty, Please provide User Name"));
		}
	}

	CEdit* pCEditUserPassword = (CEdit*)GetDlgItem(IDC_EDIT_USERPASSWRD);
	if (pCEditUserPassword != nullptr)
	{
		pCEditUserPassword->GetWindowTextW(strUserPassword);
		if (strUserPassword.IsEmpty())
		{
			AfxMessageBox(_T("Please provide Password"));
		}
	}
	if (ulogin.dbconnectioncheck())
	{
		if (!ulogin.login(strUserRole, strUserName, strUserPassword))
		{
			if (IDOK == MessageBox(_T("User Name and Password is wrong. please try again.")))
			{
				return;
			}
		}
		else
		{
			dlgDoctorAppoinment.user = ulogin;
			dlgDoctorAppoinment.dbconnect = ulogin.dbconnect;
			OnCancel();
			dlgDoctorAppoinment.DoModal();
		}
	}
	else
	{
		return;
	}
}


void CLoginDlg::OnBnClickedMfcbuttonCancle()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

BOOL CLoginDlg::OnEraseBkgnd(CDC* pDC)
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
