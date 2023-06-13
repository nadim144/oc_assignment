// CTabDoctors.cpp : implementation file
//

#include "pch.h"
#include "DoctorAppointment.h"
#include "afxdialogex.h"
#include "CTabDoctors.h"


// CTabDoctors dialog

IMPLEMENT_DYNAMIC(CTabDoctors, CDialogEx)

CTabDoctors::CTabDoctors(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_DOCTORS, pParent)
{
	m_CListCtrlDoctor = nullptr;
	m_RowCount = 0;
}

CTabDoctors::~CTabDoctors()
{
}

void CTabDoctors::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabDoctors, CDialogEx)
	ON_BN_CLICKED(IDC_BTTN_ADDDOCTORS, &CTabDoctors::OnBnClickedBttnAdddoctors)
	ON_BN_CLICKED(IDC_BTTN_DOCTOR_REFRESH, &CTabDoctors::OnBnClickedBttnDoctorRefresh)
END_MESSAGE_MAP()


// CTabDoctors message handlers
//


BOOL CTabDoctors::OnInitDialog()
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

	GetDlgItem(IDC_STATIC_TXT_ADDDOCTORS)->SetFont(&font);

	// List Ctrl for Add Doctors
	CRect dRect;
	m_CListCtrlDoctor = (CListCtrl*)GetDlgItem(IDC_LIST_ADDNEWDOCTORS);
	m_CListCtrlDoctor->GetClientRect(&dRect);
	m_CListCtrlDoctor->InsertColumn(0, _T("SN."), 0, dRect.Width() / 9);
	m_CListCtrlDoctor->InsertColumn(1, _T("First Name"), 0, dRect.Width() / 9);
	m_CListCtrlDoctor->InsertColumn(2, _T("Last Name"), 0, dRect.Width() / 9);
	m_CListCtrlDoctor->InsertColumn(3, _T("Specialization"), 0, dRect.Width() / 9);
	m_CListCtrlDoctor->InsertColumn(4, _T("Email Id"), 0, dRect.Width() / 9);
	m_CListCtrlDoctor->InsertColumn(5, _T("Mobile No."), 0, dRect.Width() / 9);
	m_CListCtrlDoctor->InsertColumn(6, _T("Location"), 0, dRect.Width() / 9);
	m_CListCtrlDoctor->InsertColumn(7, _T("State"), 0, dRect.Width() / 9);
	m_CListCtrlDoctor->InsertColumn(8, _T("Country"), 0, dRect.Width() / 9);

	return TRUE;
}

void CTabDoctors::SetDatabaseConnect(CDatabaseConnect& d)
{
	dbconnect = d;
}


CDatabaseConnect& CTabDoctors::GetDatabaseConnect()
{
	return dbconnect;
}

void CTabDoctors::AddData(CListCtrl* ctrl, unsigned int row, unsigned int col, const CString str)

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

void CTabDoctors::UpdateListCtrl()
{
	std::string query = "SELECT * FROM oc_assignment._doctors";
	const char* q = query.c_str();
	dbconnect.querystate = mysql_query(dbconnect.m_Connection, q);
	if (!dbconnect.querystate)
	{
		dbconnect.m_Res = mysql_store_result(dbconnect.m_Connection);
		while (dbconnect.m_Row = mysql_fetch_row(dbconnect.m_Res))
		{
			AddData(m_CListCtrlDoctor, m_RowCount, static_cast<unsigned int>(0U), CString(dbconnect.m_Row[0]));
			AddData(m_CListCtrlDoctor, m_RowCount, static_cast<unsigned int>(1U), CString(dbconnect.m_Row[1]));
			AddData(m_CListCtrlDoctor, m_RowCount, static_cast<unsigned int>(2U), CString(dbconnect.m_Row[2]));
			AddData(m_CListCtrlDoctor, m_RowCount, static_cast<unsigned int>(3U), CString(dbconnect.m_Row[3]));
			AddData(m_CListCtrlDoctor, m_RowCount, static_cast<unsigned int>(4U), CString(dbconnect.m_Row[4]));
			AddData(m_CListCtrlDoctor, m_RowCount, static_cast<unsigned int>(5U), CString(dbconnect.m_Row[5]));
			AddData(m_CListCtrlDoctor, m_RowCount, static_cast<unsigned int>(6U), CString(dbconnect.m_Row[6]));
			AddData(m_CListCtrlDoctor, m_RowCount, static_cast<unsigned int>(7U), CString(dbconnect.m_Row[7]));
			AddData(m_CListCtrlDoctor, m_RowCount, static_cast<unsigned int>(8U), CString(dbconnect.m_Row[8]));
			m_RowCount++;
		}
	}
}

void CTabDoctors::OnBnClickedBttnAdddoctors()
{
	// TODO: Add your control notification handler code here
	AddDoctorsdlg.SetDatabaseConnect(dbconnect);
	AddDoctorsdlg.DoModal();
}


void CTabDoctors::OnBnClickedBttnDoctorRefresh()
{
	// TODO: Add your control notification handler code here
	m_CListCtrlDoctor->DeleteAllItems();
	m_RowCount = static_cast<unsigned int>(0U);
	UpdateListCtrl();
}
