// CComputerScience.cpp : implementation file
//

#include "pch.h"
#include "LifePlanning.h"
#include "afxdialogex.h"
#include "CComputerScience.h"


// CComputerScience dialog

IMPLEMENT_DYNAMIC(CComputerScience, CMFCPropertyPage)

CComputerScience::CComputerScience(CWnd* pParent /*=nullptr*/)
	: CMFCPropertyPage(IDD_PROPPAGE_COMPUTERSCIENCE)
{

}

CComputerScience::~CComputerScience()
{
}

void CComputerScience::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CComputerScience, CMFCPropertyPage)
END_MESSAGE_MAP()


// CComputerScience message handlers
