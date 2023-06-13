#pragma once
#include "CDatabaseConnect.h"

class CPatientsDetails
{
public:
	CString m_strPatientsFirstName;
	CString m_strPatientsLastName;
	CString m_strPatientsEmailId;
	CString m_strPatientsMobile;
	CString m_strPatientsLocation;
	CString m_strPatientsState;
	CString m_strPatientsCountry;
public:
	CPatientsDetails();
	~CPatientsDetails();
	bool SavePatientDetailsToDB(CString DocfName, CString DoclName, CString DocEmail,
		CString DocMobile, CString DocLocation, CString DocState, CString DocCountry);

	void SetDatabaseConnect(CDatabaseConnect& d);
	CDatabaseConnect& GetDatabaseConnect();

public:
	CDatabaseConnect	dbconnect;
};

