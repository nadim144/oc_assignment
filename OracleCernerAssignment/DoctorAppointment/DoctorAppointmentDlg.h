
// DoctorAppointmentDlg.h : header file
//

#pragma once
#include "CTabDashboard.h"
#include "CTabDoctors.h"
#include "CTabSchedule.h"
#include "CTabAppointment.h"
#include "CTabPatient.h"
#include "CDoctorsDetails.h"
#include "CDatabaseConnect.h"
#include "CUserLogin.h"

// CDoctorAppointmentDlg dialog
class CDoctorAppointmentDlg : public CDialogEx
{
// Construction
public:
	CDoctorAppointmentDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_DOCTORAPPOINTMENT };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CStatic m_static_logedin_username;
	CStatic m_static_logedin_useremail;
public:
	CFont				font;
	CEdit				m_edit_searchfield;
	CTabDashboard		m_TabDashboard;
	CTabDoctors			m_TabDoctors;
	CTabSchedule		m_TabSchedule;
	CTabAppointment		m_TabAppointment;
	CTabPatient			m_TabPatient;
	CDoctorsDetails		m_DoctorsDetails;
	CUserLogin			user;
	CDatabaseConnect	dbconnect;

	void DisableTabDialog();
	afx_msg void OnBnClickedBttnSearch();
	afx_msg void OnBnClickedBttnLogout();
	afx_msg void OnBnClickedButtonDashboard();
	afx_msg void OnBnClickedButtonDoctors();
	afx_msg void OnBnClickedButtonSchedule();
	afx_msg void OnBnClickedButtonAppointment();
	afx_msg void OnBnClickedButtonPatient();
};
