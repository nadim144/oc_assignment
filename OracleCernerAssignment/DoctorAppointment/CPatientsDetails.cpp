#include "pch.h"
#include "CPatientsDetails.h"


CPatientsDetails::CPatientsDetails(): 
  m_strPatientsFirstName(_T(""))
, m_strPatientsLastName(_T(""))
, m_strPatientsEmailId(_T(""))
, m_strPatientsMobile(_T(""))
, m_strPatientsLocation(_T(""))
, m_strPatientsState(_T(""))
, m_strPatientsCountry(_T(""))

{
	//Default Controctor
}

CPatientsDetails::~CPatientsDetails()
{
	//Default Destructor
}

void CPatientsDetails::SetDatabaseConnect(CDatabaseConnect& d)
{
	dbconnect = d;
}

CDatabaseConnect& CPatientsDetails::GetDatabaseConnect()
{
	return dbconnect;
}

bool CPatientsDetails::SavePatientDetailsToDB(CString PatientfName, CString PatientlName, CString PatientEmail, CString PatientMobile, CString PatientLocation, 
	CString PatientState, CString PatientCountry)
{
	m_strPatientsFirstName = PatientfName;
	m_strPatientsLastName = PatientlName;
	m_strPatientsEmailId = PatientEmail;
	m_strPatientsMobile = PatientMobile;
	m_strPatientsLocation = PatientLocation;
	m_strPatientsState = PatientState;
	m_strPatientsCountry = PatientCountry;

	//INSERT INTO _doctors(fName, lName, specialization,emailid,mobileno,location,state,country) VALUES("Nadim". "Ahmad", "Orthopedics", "ahmad@gmail.com", 9738455404, "Supaul", "Bihar", "INDIA");

	//std::string query = "INSERT INTO _doctors(fName, lName, specialization, emailid, mobileno, location, state, country) VALUES(m_strDoctorFirstName, m_strDoctorLastName, m_strDoctorSpecialization, m_strDoctorEmailId, m_str_DoctorMobile, m_strDoctorLocation, m_strDoctorState, m_strDoctorCountry)";

	CString strQuery;
	strQuery.Format(_T("INSERT INTO _patient(fName, lName, emailid, mobileno, location, state, country) VALUES('%s', '%s', '%s', '%s', '%s', '%s', '%s')"),
		m_strPatientsFirstName,
		m_strPatientsLastName,
		m_strPatientsEmailId,
		m_strPatientsMobile,
		m_strPatientsLocation,
		m_strPatientsState,
		m_strPatientsCountry);

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

	//return true;
}