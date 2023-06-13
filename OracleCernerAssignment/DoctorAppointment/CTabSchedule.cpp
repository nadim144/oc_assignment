// CTabSchedule.cpp : implementation file
//

#include "pch.h"
#include "DoctorAppointment.h"
#include "afxdialogex.h"
#include "CTabSchedule.h"


// CTabSchedule dialog

IMPLEMENT_DYNAMIC(CTabSchedule, CDialogEx)

CTabSchedule::CTabSchedule(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_SCHEDULE, pParent)
{

}

CTabSchedule::~CTabSchedule()
{
}

void CTabSchedule::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabSchedule, CDialogEx)
END_MESSAGE_MAP()


// CTabSchedule message handlers
//void CTabSchedule::SetDatabaseConnect(CDatabaseConnect& d)
//{
//	dbconnect = d;
//}
//
//CDatabaseConnect& CTabSchedule::GetDatabaseConnect()
//{
//	return dbconnect;
//}

BOOL CTabSchedule::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
