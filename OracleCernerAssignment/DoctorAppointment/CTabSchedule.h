#pragma once
#include "afxdialogex.h"
//#include "CDatabaseConnect.h"


// CTabSchedule dialog

class CTabSchedule : public CDialogEx
{
	DECLARE_DYNAMIC(CTabSchedule)

public:
	CTabSchedule(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTabSchedule();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_SCHEDULE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
public:
	//void SetDatabaseConnect(CDatabaseConnect& d);
	//CDatabaseConnect& GetDatabaseConnect();
public:
	//CDatabaseConnect	dbconnect;

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
};
