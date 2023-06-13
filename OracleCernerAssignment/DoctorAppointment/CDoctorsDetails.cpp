#include "pch.h"
#include "CDoctorsDetails.h"


CDoctorsDetails::CDoctorsDetails()
{
	//Default Controctor
}

CDoctorsDetails::~CDoctorsDetails()
{
	//Default Destructor
}

void CDoctorsDetails::SetDatabaseConnect(CDatabaseConnect& d)
{
	dbconnect = d;
}

CDatabaseConnect& CDoctorsDetails::GetDatabaseConnect()
{
	return dbconnect;
}

bool CDoctorsDetails::DoctorDetailsSaveToDB(CString DocfName, CString DoclName, CString DocSpecialization, CString DocEmail,
	CString DocMobile, CString DocLocation, CString DocState, CString DocCountry)
{
	m_strDoctorFirstName		= DocfName;
	m_strDoctorLastName			= DoclName;
	m_strDoctorSpecialization	= DocSpecialization;
	m_strDoctorEmailId			= DocEmail;
	m_str_DoctorMobile			= DocMobile;
	m_strDoctorLocation			= DocLocation;
	m_strDoctorState			= DocState;
	m_strDoctorCountry			= DocCountry;
	
	//INSERT INTO _doctors(fName, lName, specialization,emailid,mobileno,location,state,country) VALUES("Nadim". "Ahmad", "Orthopedics", "ahmad@gmail.com", 9738455404, "Supaul", "Bihar", "INDIA");
	
	std::string query = "INSERT INTO _doctors(fName, lName, specialization, emailid, mobileno, location, state, country) VALUES(m_strDoctorFirstName, m_strDoctorLastName, m_strDoctorSpecialization, m_strDoctorEmailId, m_str_DoctorMobile, m_strDoctorLocation, m_strDoctorState, m_strDoctorCountry)";
	
	CString strQuery;
	strQuery.Format(_T("INSERT INTO _doctors(fName, lName, specialization, emailid, mobileno, location, state, country) VALUES('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s')"),
		m_strDoctorFirstName,
		m_strDoctorLastName,
		m_strDoctorSpecialization,
		m_strDoctorEmailId,
		m_str_DoctorMobile, 
		m_strDoctorLocation,
		m_strDoctorState,
		m_strDoctorCountry);
	
	CStringA charstr(strQuery);

	const char* q = (const char*)charstr;
	dbconnect.querystate = mysql_query(dbconnect.m_Connection, q);

	if (!dbconnect.querystate)
	{
		return true;
	}
	else
	{
		return false;
	}

	
}