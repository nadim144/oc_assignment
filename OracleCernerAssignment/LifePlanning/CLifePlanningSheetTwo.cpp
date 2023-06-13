// CLifePlanningSheetTwo.cpp : implementation file
//

#include "pch.h"
#include "LifePlanning.h"
#include "CLifePlanningSheetTwo.h"


// CLifePlanningSheetTwo

IMPLEMENT_DYNAMIC(CLifePlanningSheetTwo, CPropertySheet)

CLifePlanningSheetTwo::CLifePlanningSheetTwo(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CMFCPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

CLifePlanningSheetTwo::CLifePlanningSheetTwo(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CMFCPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}

CLifePlanningSheetTwo::~CLifePlanningSheetTwo()
{
}


BEGIN_MESSAGE_MAP(CLifePlanningSheetTwo, CMFCPropertySheet)
END_MESSAGE_MAP()


// CLifePlanningSheetTwo message handlers
