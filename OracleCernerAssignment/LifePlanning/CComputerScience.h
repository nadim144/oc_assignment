#pragma once
#include "afxdialogex.h"


// CComputerScience dialog

class CComputerScience : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(CComputerScience)

public:
	CComputerScience(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CComputerScience();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPPAGE_COMPUTERSCIENCE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
