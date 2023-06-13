#pragma once
#include "CDatabaseConnect.h"

class CDoctorsDetails
{
public:
	CString m_strDoctorFirstName;
	CString m_strDoctorLastName;
	CString m_strDoctorSpecialization;
	CString m_strDoctorEmailId;
	CString m_str_DoctorMobile;
	CString m_strDoctorLocation;
	CString m_strDoctorState;
	CString m_strDoctorCountry;
public:
	CDoctorsDetails();
	~CDoctorsDetails();
	bool DoctorDetailsSaveToDB(CString DocfName, CString DoclName, CString DocSpecialization, CString DocEmail,
		CString DocMobile, CString DocLocation, CString DocState, CString DocCountry);

	void SetDatabaseConnect(CDatabaseConnect& d);
	CDatabaseConnect& GetDatabaseConnect();

public:
	CDatabaseConnect	dbconnect;
};

