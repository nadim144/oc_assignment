#pragma once
#include "afxdialogex.h"
#include "CAddDoctorsDlg.h"
#include "CDatabaseConnect.h"


// CTabDoctors dialog

class CTabDoctors : public CDialogEx
{
	DECLARE_DYNAMIC(CTabDoctors)

public:
	CTabDoctors(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTabDoctors();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_DOCTORS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
public:
	void AddData(CListCtrl* ctrl, unsigned int row, unsigned int col, const CString str);

	void SetDatabaseConnect(CDatabaseConnect& d);
	CDatabaseConnect& GetDatabaseConnect();
	void UpdateListCtrl();

public:
	CListCtrl*			m_CListCtrlDoctor;
	CDatabaseConnect	dbconnect;
	unsigned int		m_RowCount;
	CAddDoctorsDlg		AddDoctorsdlg;


	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedBttnAdddoctors();
	afx_msg void OnBnClickedBttnDoctorRefresh();
};
