// CTabDashboard.cpp : implementation file
//

#include "pch.h"
#include "DoctorAppointment.h"
#include "afxdialogex.h"
#include "CTabDashboard.h"
#include "CDoctorsDetails.h"

// CTabDashboard dialog

IMPLEMENT_DYNAMIC(CTabDashboard, CDialogEx)

CTabDashboard::CTabDashboard(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_DASHBOARD, pParent)
{

}

CTabDashboard::~CTabDashboard()
{
}

void CTabDashboard::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_TEXT_DOCTORSCOUNT, m_DoctorsCount);
	DDX_Control(pDX, IDC_STATIC_TEXT_PATIENTCOUNT, m_PatienstCount);
	DDX_Control(pDX, IDC_STATIC_TEXT_NEWBOOKINGCOUNT, m_NewBookingCount);
	DDX_Control(pDX, IDC_STATIC_TEXT_TODAYSESSIONS, m_TodaySessions);
}

BOOL CTabDashboard::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Customize Satus text font and size 
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

	GetDlgItem(IDC_STATIC_TEXT_STATUS)->SetFont(&font);
	GetDlgItem(IDC_STATIC_TEXT_DOCTORS)->SetFont(&font);
	GetDlgItem(IDC_STATIC_TEXT_PATIENT)->SetFont(&font);
	GetDlgItem(IDC_STATIC_TEXT_NEWBOOKING)->SetFont(&font);
	GetDlgItem(IDC_STATIC_TEXT_TODAYSESSION)->SetFont(&font);

	// List Ctrl for Doctors info
	CRect dRect;
	CListCtrl* pCListCtrlDoctor = (CListCtrl*)GetDlgItem(IDC_LIST_ADDDOCTOR);
	pCListCtrlDoctor->GetClientRect(&dRect);
	pCListCtrlDoctor->InsertColumn(0, _T("Appointment No."), 0, dRect.Width()/4);
	pCListCtrlDoctor->InsertColumn(1, _T("Patient Name"), 0, dRect.Width()/4);
	pCListCtrlDoctor->InsertColumn(2, _T("Doctor"), 0, dRect.Width()/4);
	pCListCtrlDoctor->InsertColumn(3, _T("Session"), 0, dRect.Width()/4);

	// List Ctrl for Patient info
	CRect pRect;
	CListCtrl* pCListCtrlPatient = (CListCtrl*)GetDlgItem(IDC_LIST_PATIENT);
	pCListCtrlPatient->GetClientRect(&pRect);
	pCListCtrlPatient->InsertColumn(0, _T("Session Title"), 0, pRect.Width() / 3);
	pCListCtrlPatient->InsertColumn(1, _T("Doctor"), 0, pRect.Width() / 3);
	pCListCtrlPatient->InsertColumn(2, _T("Date & Time"), 0, pRect.Width() / 3);

	return TRUE;
}


BEGIN_MESSAGE_MAP(CTabDashboard, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADDDOCTOR, &CTabDashboard::OnBnClickedButtonAdddoctor)
	ON_BN_CLICKED(IDC_BUTTON_ADDPATIENT, &CTabDashboard::OnBnClickedButtonAddpatient)
	ON_BN_CLICKED(IDC_BUTTON_ADDNEWBOOKING, &CTabDashboard::OnBnClickedButtonAddnewbooking)
	ON_BN_CLICKED(IDC_BUTTON_ADDTODAYSESSION, &CTabDashboard::OnBnClickedButtonAddtodaysession)
END_MESSAGE_MAP()


// CTabDashboard message handlers

void CTabDashboard::SetDatabaseConnect(CDatabaseConnect& d)
{
	dbconnect = d;
}

CDatabaseConnect& CTabDashboard::GetDatabaseConnect()
{
	return dbconnect;
}

void CTabDashboard::OnBnClickedButtonAdddoctor()
{
	// TODO: Add your control notification handler code here
	AddDoctorsdlg.SetDatabaseConnect(dbconnect);
	AddDoctorsdlg.DoModal();
}


void CTabDashboard::OnBnClickedButtonAddpatient()
{
	// TODO: Add your control notification handler code here
	AddPatientdlg.SetDatabaseConnect(dbconnect);
	AddPatientdlg.DoModal();

}


void CTabDashboard::OnBnClickedButtonAddnewbooking()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox(_T("TODO: Add New Booking ..."));

}


void CTabDashboard::OnBnClickedButtonAddtodaysession()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox(_T("TODO: Add Today Sessions ..."));

}
