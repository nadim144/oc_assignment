#pragma once

#include "afxdialogex.h"
#include "DoctorAppointmentDlg.h"
#include "CDatabaseConnect.h"


// CLoginDlg dialog

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CLoginDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	CDoctorAppointmentDlg dlgDoctorAppoinment;
public:
	CComboBox m_combo_userrole;
	CEdit m_edit_username;
	CEdit m_edit_userpassword;
	CMFCButton m_MFCBttn_Login;
	CMFCButton m_MFCBttn_Cancle;
	
public:
	afx_msg void OnCbnSelchangeComboUserrole();
	afx_msg void OnBnClickedMfcbuttonLogin();
	afx_msg void OnBnClickedMfcbuttonCancle();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
