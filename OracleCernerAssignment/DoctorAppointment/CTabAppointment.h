#pragma once
#include "afxdialogex.h"
//#include "CDatabaseConnect.h"


// CTabAppointment dialog

class CTabAppointment : public CDialogEx
{
	DECLARE_DYNAMIC(CTabAppointment)

public:
	CTabAppointment(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTabAppointment();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_APPOINTMENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	//void SetDatabaseConnect(CDatabaseConnect& d);
	//CDatabaseConnect& GetDatabaseConnect();
public:
	//CDatabaseConnect	dbconnect;
};
