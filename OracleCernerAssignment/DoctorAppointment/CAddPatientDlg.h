#pragma once
#include "CDatabaseConnect.h"
#include "CPatientsDetails.h"

// CAddPatientDlg dialog

class CAddPatientDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddPatientDlg)

public:
	CAddPatientDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddPatientDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_ADD_PATIENTS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit_Patient_FName;
	CEdit m_edit_Patient_LName;
	CEdit m_edit_Patient_Email;
	CEdit m_edit_Patient_Mobile;
	CEdit m_edit_Patient_Location;
	CEdit m_edit_Patient_State;
	CEdit m_edit_Patient_Country;


	CString m_str_Patient_FName;
	CString m_str_Patient_LName;
	CString m_str_Patient_Email;
	CString m_str_Patient_Mobile;
	CString m_str_Patient_Location;
	CString m_str_Patient_State;
	CString m_str_Patient_Country;
	CDatabaseConnect		dbconnect;
	CPatientsDetails		objPatientDetails;

public:

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBttnReset();
	afx_msg void OnBnClickedBttnSubmit();
	afx_msg void OnBnClickedCancel();

	void ResetControls();
	void SetDatabaseConnect(CDatabaseConnect& d);
	CDatabaseConnect& GetDatabaseConnect();

};
