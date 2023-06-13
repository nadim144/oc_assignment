#pragma once
#include "afxdialogex.h"
#include "CAddDoctorsDlg.h"
#include "CAddPatientDlg.h"
#include "CDoctorsDetails.h"
#include "CDatabaseConnect.h"
// CTabDashboard dialog

class CTabDashboard : public CDialogEx
{
	DECLARE_DYNAMIC(CTabDashboard)

public:
	CTabDashboard(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTabDashboard();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_DASHBOARD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_DoctorsCount;
	CStatic m_PatienstCount;
	CStatic m_NewBookingCount;
	CStatic m_TodaySessions;
	afx_msg void OnBnClickedButtonAdddoctor();
	afx_msg void OnBnClickedButtonAddpatient();
	afx_msg void OnBnClickedButtonAddnewbooking();
	afx_msg void OnBnClickedButtonAddtodaysession();

	void SetDatabaseConnect(CDatabaseConnect& d);
	CDatabaseConnect& GetDatabaseConnect();
public:
	CAddDoctorsDlg		AddDoctorsdlg;
	CAddPatientDlg		AddPatientdlg;
	CDatabaseConnect	dbconnect;
};
