#pragma once

#include "CDoctorsDetails.h"
#include "CDatabaseConnect.h"
// CAddDoctorsDlg dialog

class CAddDoctorsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddDoctorsDlg)

public:
	CAddDoctorsDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddDoctorsDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_ADDDOCTORS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit		m_DocFirstName;
	CEdit		m_DocLastName;
	CComboBox	m_DocSpecialization;
	CEdit		m_DocEmailId;
	CEdit		m_DocMobileNumber;
	CEdit		m_DocLocation;
	CEdit		m_DocState;
	CEdit		m_DocCountry;
	afx_msg void OnBnClickedBttnReset();
	afx_msg void OnBnClickedBttnSubmit();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	void ResetControls();
	
	void SetDatabaseConnect(CDatabaseConnect& d);
	CDatabaseConnect& GetDatabaseConnect();

public:

	CDatabaseConnect	dbconnect;
	CDoctorsDetails		objDoctorsDetails;

	CString m_strDoctorFirstName;
	CString m_strDoctorLastName;
	CString m_strDoctorSpecialization;
	CString m_strDoctorEmailId;
	CString m_str_DoctorMobile;
	CString m_strDoctorLocation;
	CString m_strDoctorState;
	CString m_strDoctorCountry;
};
