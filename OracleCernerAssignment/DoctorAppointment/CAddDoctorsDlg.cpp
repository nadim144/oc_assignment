// CAddDoctorsDlg.cpp : implementation file
//

#include "pch.h"
#include "DoctorAppointment.h"
#include "CAddDoctorsDlg.h"
#include "afxdialogex.h"
#include "CDoctorsDetails.h"

// CAddDoctorsDlg dialog

IMPLEMENT_DYNAMIC(CAddDoctorsDlg, CDialogEx)

CAddDoctorsDlg::CAddDoctorsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_ADDDOCTORS, pParent)
	, m_strDoctorFirstName(_T(""))
	, m_strDoctorLastName(_T(""))
	, m_strDoctorSpecialization(_T(""))
	, m_strDoctorEmailId(_T(""))
	, m_str_DoctorMobile(_T(""))
	, m_strDoctorLocation(_T(""))
	, m_strDoctorState(_T(""))
	, m_strDoctorCountry(_T(""))
{

}

CAddDoctorsDlg::~CAddDoctorsDlg()
{
}

void CAddDoctorsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_DOCFIRSTNAME, m_DocFirstName);
	DDX_Control(pDX, IDC_EDIT_DOCLASTNAME, m_DocLastName);
	DDX_Control(pDX, IDC_COMBO1, m_DocSpecialization);
	DDX_Control(pDX, IDC_EDIT_DOCEMAILID, m_DocEmailId);
	DDX_Control(pDX, IDC_EDIT_DOCMOBILE, m_DocMobileNumber);
	DDX_Control(pDX, IDC_EDIT_DOCLOCATION, m_DocLocation);
	DDX_Control(pDX, IDC_EDIT_DOCSTATE, m_DocLocation);
	DDX_Control(pDX, IDC_EDIT_DOCCOUNTRY, m_DocCountry);
	DDX_Text(pDX, IDC_EDIT_DOCFIRSTNAME, m_strDoctorFirstName);
	DDX_Text(pDX, IDC_EDIT_DOCLASTNAME, m_strDoctorLastName);
	DDX_CBString(pDX, IDC_COMBO1, m_strDoctorSpecialization);
	DDX_Text(pDX, IDC_EDIT_DOCEMAILID, m_strDoctorEmailId);
	DDX_Text(pDX, IDC_EDIT_DOCMOBILE, m_str_DoctorMobile);
	DDX_Text(pDX, IDC_EDIT_DOCLOCATION, m_strDoctorLocation);
	DDX_Text(pDX, IDC_EDIT_DOCSTATE, m_strDoctorState);
	DDX_Text(pDX, IDC_EDIT_DOCCOUNTRY, m_strDoctorCountry);
}


BEGIN_MESSAGE_MAP(CAddDoctorsDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTTN_RESET, &CAddDoctorsDlg::OnBnClickedBttnReset)
	ON_BN_CLICKED(IDC_BTTN_SUBMIT, &CAddDoctorsDlg::OnBnClickedBttnSubmit)
	ON_BN_CLICKED(IDCANCEL, &CAddDoctorsDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CAddDoctorsDlg message handlers

BOOL CAddDoctorsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_DocSpecialization.AddString(_T("Internal medicine"));
	m_DocSpecialization.AddString(_T("Orthopedics"));
	m_DocSpecialization.AddString(_T("Neurology"));
	m_DocSpecialization.AddString(_T("Gastroenterology"));
	m_DocSpecialization.AddString(_T("Ophthalmology"));
	m_DocSpecialization.AddString(_T("Anesthesiology"));
	m_DocSpecialization.AddString(_T("Surgeon"));
	m_DocSpecialization.AddString(_T("Neurosurgery"));
	m_DocSpecialization.AddString(_T("Pediatrics"));
	m_DocSpecialization.AddString(_T("Family medicine"));
	m_DocSpecialization.SelectString(0, _T("Internal medicine"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddDoctorsDlg::OnBnClickedBttnReset()
{
	// TODO: Add your control notification handler code here
	ResetControls();
}

void CAddDoctorsDlg::ResetControls()
{
	m_strDoctorFirstName = _T("");
	m_strDoctorLastName = _T("");
	m_strDoctorEmailId = _T("");
	m_str_DoctorMobile = _T("");
	m_strDoctorLocation = _T("");
	m_strDoctorState = _T("");
	m_strDoctorCountry = _T("");
	UpdateData(FALSE);
}

void CAddDoctorsDlg::SetDatabaseConnect(CDatabaseConnect& d)
{
	dbconnect = d;
}

CDatabaseConnect& CAddDoctorsDlg::GetDatabaseConnect()
{
	return dbconnect;
}

void CAddDoctorsDlg::OnBnClickedBttnSubmit()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	objDoctorsDetails.SetDatabaseConnect(dbconnect);
	bool bflag = objDoctorsDetails.DoctorDetailsSaveToDB(m_strDoctorFirstName, m_strDoctorLastName, m_strDoctorSpecialization, m_strDoctorEmailId,
															m_str_DoctorMobile, m_strDoctorLocation, m_strDoctorState, m_strDoctorCountry);
	if (bflag)
	{
		if (IDOK == MessageBox(_T("Data save successfully ...")))
		{
			CDialogEx::OnOK();
		}
	}
}

void CAddDoctorsDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}



