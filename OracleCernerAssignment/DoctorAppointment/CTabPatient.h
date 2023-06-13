#pragma once
#include "afxdialogex.h"
#include "CDatabaseConnect.h"
#include "CAddPatientDlg.h"


// CTabPatient dialog

class CTabPatient : public CDialogEx
{
	DECLARE_DYNAMIC(CTabPatient)

public:
	CTabPatient(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTabPatient();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_PATIENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedBttnAddpatients();

public:

	void SetDatabaseConnect(CDatabaseConnect& d);
	CDatabaseConnect& GetDatabaseConnect();
	void AddData(CListCtrl* ctrl, unsigned int row, unsigned int col, const CString str);
	void UpdateListCtrl();

public:
	CDatabaseConnect	dbconnect;
	CAddPatientDlg		AddPatientdlg;
	CListCtrl*			m_CListCtrlPatient;
	unsigned int		m_RowCount;



	DECLARE_MESSAGE_MAP()

	afx_msg void OnBnClickedBttnPatientRefresh();
};
