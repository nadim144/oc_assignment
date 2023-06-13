#pragma once
#include "afxdialogex.h"


// CInformationTechnology dialog

class CInformationTechnology : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(CInformationTechnology)

public:
	CInformationTechnology(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CInformationTechnology();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPPAGE_INFORMATIONTECHNOLOGY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
