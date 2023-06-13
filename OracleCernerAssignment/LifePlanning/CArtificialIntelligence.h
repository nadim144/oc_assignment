#pragma once
#include "afxdialogex.h"


// CArtificialIntelligence dialog

class CArtificialIntelligence : public CDialogEx
{
	DECLARE_DYNAMIC(CArtificialIntelligence)

public:
	CArtificialIntelligence(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CArtificialIntelligence();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPPAGE_ARTIFICIALINTELLIGENCE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
