// CTabAppointment.cpp : implementation file
//

#include "pch.h"
#include "DoctorAppointment.h"
#include "afxdialogex.h"
#include "CTabAppointment.h"


// CTabAppointment dialog

IMPLEMENT_DYNAMIC(CTabAppointment, CDialogEx)

CTabAppointment::CTabAppointment(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_APPOINTMENT, pParent)
{

}

CTabAppointment::~CTabAppointment()
{
}

void CTabAppointment::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabAppointment, CDialogEx)
END_MESSAGE_MAP()


// CTabAppointment message handlers

//void CTabAppointment::SetDatabaseConnect(CDatabaseConnect& d)
//{
//	dbconnect = d;
//}
//
//CDatabaseConnect& CTabAppointment::GetDatabaseConnect()
//{
//	return dbconnect;
//}

BOOL CTabAppointment::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
