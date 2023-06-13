#pragma once



// CLifePlanningSheetTwo

class CLifePlanningSheetTwo : public CMFCPropertySheet
{
	DECLARE_DYNAMIC(CLifePlanningSheetTwo)

public:
	CLifePlanningSheetTwo(UINT nIDCaption, CWnd* pParentWnd = nullptr, UINT iSelectPage = 0);
	CLifePlanningSheetTwo(LPCTSTR pszCaption, CWnd* pParentWnd = nullptr, UINT iSelectPage = 0);
	virtual ~CLifePlanningSheetTwo();

protected:
	DECLARE_MESSAGE_MAP()
};


