// CTabPatient.cpp : implementation file
//

#include "pch.h"
#include "DoctorAppointment.h"
#include "afxdialogex.h"
#include "CTabPatient.h"


// CTabPatient dialog

IMPLEMENT_DYNAMIC(CTabPatient, CDialogEx)

CTabPatient::CTabPatient(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_PATIENT, pParent)
	, m_CListCtrlPatient(nullptr)
	, m_RowCount(0)
{

}

CTabPatient::~CTabPatient()
{
}

void CTabPatient::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabPatient, CDialogEx)
	ON_BN_CLICKED(IDC_BTTN_ADDPATIENTS, &CTabPatient::OnBnClickedBttnAddpatients)
	ON_BN_CLICKED(IDC_BTTN_PATIENT_REFRESH, &CTabPatient::OnBnClickedBttnPatientRefresh)
END_MESSAGE_MAP()


// CTabPatient message handlers

void CTabPatient::SetDatabaseConnect(CDatabaseConnect& d)
{
	dbconnect = d;
}

CDatabaseConnect& CTabPatient::GetDatabaseConnect()
{
	return dbconnect;
}

BOOL CTabPatient::OnInitDialog()
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

	GetDlgItem(IDC_STATIC_TXT_ADDPATIENTS)->SetFont(&font);

	// List Ctrl for Add Doctors
	CRect dRect;
	m_CListCtrlPatient = (CListCtrl*)GetDlgItem(IDC_LIST_ADDNEWPATIENTS);
	m_CListCtrlPatient->GetClientRect(&dRect);
	m_CListCtrlPatient->InsertColumn(0, _T("SN."), 0, dRect.Width() / static_cast<unsigned short>(8));
	m_CListCtrlPatient->InsertColumn(1, _T("First Name"), 0, dRect.Width() / static_cast<unsigned short>(8));
	m_CListCtrlPatient->InsertColumn(2, _T("Last Name"), 0, dRect.Width() / static_cast<unsigned short>(8));
	m_CListCtrlPatient->InsertColumn(4, _T("Email Id"), 0, dRect.Width() / static_cast<unsigned short>(8));
	m_CListCtrlPatient->InsertColumn(5, _T("Mobile No."), 0, dRect.Width() / static_cast<unsigned short>(8));
	m_CListCtrlPatient->InsertColumn(6, _T("Location"), 0, dRect.Width() / static_cast<unsigned short>(8));
	m_CListCtrlPatient->InsertColumn(7, _T("State"), 0, dRect.Width() / static_cast<unsigned short>(8));
	m_CListCtrlPatient->InsertColumn(8, _T("Country"), 0, dRect.Width() / static_cast<unsigned short>(8));


	return TRUE;  
}

void CTabPatient::AddData(CListCtrl* ctrl, unsigned int row, unsigned int col, const CString str)

{
	LVITEM lv;
	lv.iItem = row;
	lv.iSubItem = col;
	lv.pszText = (LPWSTR)(LPCWSTR)str;
	lv.mask = LVIF_TEXT;
	if (col == 0)
		ctrl->InsertItem(&lv);
	else
		ctrl->SetItem(&lv);
}

void CTabPatient::UpdateListCtrl()
{
	std::string query = "SELECT * FROM oc_assignment._patient";
	const char* q = query.c_str();
	dbconnect.querystate = mysql_query(dbconnect.m_Connection, q);
	if (!dbconnect.querystate)
	{
		dbconnect.m_Res = mysql_store_result(dbconnect.m_Connection);
		while (dbconnect.m_Row = mysql_fetch_row(dbconnect.m_Res))
		{
			AddData(m_CListCtrlPatient, m_RowCount, static_cast<unsigned int>(0U), CString(dbconnect.m_Row[0]));
			AddData(m_CListCtrlPatient, m_RowCount, static_cast<unsigned int>(1U), CString(dbconnect.m_Row[1]));
			AddData(m_CListCtrlPatient, m_RowCount, static_cast<unsigned int>(2U), CString(dbconnect.m_Row[2]));
			AddData(m_CListCtrlPatient, m_RowCount, static_cast<unsigned int>(3U), CString(dbconnect.m_Row[3]));
			AddData(m_CListCtrlPatient, m_RowCount, static_cast<unsigned int>(4U), CString(dbconnect.m_Row[4]));
			AddData(m_CListCtrlPatient, m_RowCount, static_cast<unsigned int>(5U), CString(dbconnect.m_Row[5]));
			AddData(m_CListCtrlPatient, m_RowCount, static_cast<unsigned int>(6U), CString(dbconnect.m_Row[6]));
			AddData(m_CListCtrlPatient, m_RowCount, static_cast<unsigned int>(7U), CString(dbconnect.m_Row[7]));
			m_RowCount++;
		}
		int rowcount = mysql_num_rows(dbconnect.m_Res);
	}
}


void CTabPatient::OnBnClickedBttnAddpatients()
{
	// TODO: Add your control notification handler code here
	AddPatientdlg.SetDatabaseConnect(dbconnect);
	AddPatientdlg.DoModal();
}


void CTabPatient::OnBnClickedBttnPatientRefresh()
{
	// TODO: Add your control notification handler code here
	m_CListCtrlPatient->DeleteAllItems();
	m_RowCount = static_cast<unsigned int>(0U);
	UpdateListCtrl();
}
