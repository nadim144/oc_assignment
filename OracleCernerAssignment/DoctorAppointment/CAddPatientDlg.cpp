// CAddPatientDlg.cpp : implementation file
//

#include "pch.h"
#include "DoctorAppointment.h"
#include "CAddPatientDlg.h"
#include "afxdialogex.h"


// CAddPatientDlg dialog

IMPLEMENT_DYNAMIC(CAddPatientDlg, CDialogEx)

CAddPatientDlg::CAddPatientDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_ADD_PATIENTS, pParent)
	, m_str_Patient_FName(_T(""))
	, m_str_Patient_LName(_T(""))
	, m_str_Patient_Email(_T(""))
	, m_str_Patient_Mobile(_T(""))
	, m_str_Patient_Location(_T(""))
	, m_str_Patient_State(_T(""))
	, m_str_Patient_Country(_T(""))
{

}

CAddPatientDlg::~CAddPatientDlg()
{
}

void CAddPatientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_PATIENT_FNAME, m_edit_Patient_FName);
	DDX_Text(pDX, IDC_EDIT_PATIENT_FNAME, m_str_Patient_FName);
	DDX_Control(pDX, IDC_EDIT_PATIENT_LNAME, m_edit_Patient_LName);
	DDX_Text(pDX, IDC_EDIT_PATIENT_LNAME, m_str_Patient_LName);
	DDX_Control(pDX, IDC_EDIT_PATIENT_EMAIL, m_edit_Patient_Email);
	DDX_Text(pDX, IDC_EDIT_PATIENT_EMAIL, m_str_Patient_Email);
	DDX_Control(pDX, IDC_EDIT_PATIENT_MOBILE, m_edit_Patient_Mobile);
	DDX_Text(pDX, IDC_EDIT_PATIENT_MOBILE, m_str_Patient_Mobile);
	DDX_Control(pDX, IDC_EDIT_PATIENT_LOCATION, m_edit_Patient_Location);
	DDX_Text(pDX, IDC_EDIT_PATIENT_LOCATION, m_str_Patient_Location);
	DDX_Control(pDX, IDC_EDIT_PATIENT_STATE, m_edit_Patient_State);
	DDX_Text(pDX, IDC_EDIT_PATIENT_STATE, m_str_Patient_State);
	DDX_Control(pDX, IDC_EDIT_PATIENT_COUNTRY, m_edit_Patient_Country);
	DDX_Text(pDX, IDC_EDIT_PATIENT_COUNTRY, m_str_Patient_Country);
}


BEGIN_MESSAGE_MAP(CAddPatientDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTTN_RESET, &CAddPatientDlg::OnBnClickedBttnReset)
	ON_BN_CLICKED(IDC_BTTN_SUBMIT, &CAddPatientDlg::OnBnClickedBttnSubmit)
	ON_BN_CLICKED(IDCANCEL, &CAddPatientDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CAddPatientDlg message handlers


BOOL CAddPatientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CAddPatientDlg::OnBnClickedBttnReset()
{
	// TODO: Add your control notification handler code here
	ResetControls();
}


void CAddPatientDlg::OnBnClickedBttnSubmit()
{
	UpdateData(TRUE);
	objPatientDetails.SetDatabaseConnect(dbconnect);
	bool bflag = objPatientDetails.SavePatientDetailsToDB(m_str_Patient_FName, m_str_Patient_LName, m_str_Patient_Email,
		m_str_Patient_Mobile, m_str_Patient_Location, m_str_Patient_State, m_str_Patient_Country);
	if (bflag)
	{
		if (IDOK == MessageBox(_T("Data save successfully ...")))
		{
			CDialogEx::OnOK();
		}
	}
}


void CAddPatientDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}

void CAddPatientDlg::SetDatabaseConnect(CDatabaseConnect& d)
{
	dbconnect = d;
}

CDatabaseConnect& CAddPatientDlg::GetDatabaseConnect()
{
	return dbconnect;
}

void CAddPatientDlg::ResetControls()
{
	m_str_Patient_FName		= _T("");
	m_str_Patient_LName		= _T("");
	m_str_Patient_Email		= _T("");
	m_str_Patient_Mobile	= _T("");
	m_str_Patient_Location	= _T("");
	m_str_Patient_State		= _T("");
	m_str_Patient_Country	= _T("");
	UpdateData(FALSE);
}