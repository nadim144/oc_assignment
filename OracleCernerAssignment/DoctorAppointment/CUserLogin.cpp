#include "pch.h"
#include "CUserLogin.h"

// Default Constructor
CUserLogin::CUserLogin():diff(0)
{

}

bool CUserLogin::dbconnectioncheck()
{
	// Database connection operation
	MYSQL* dbconninitialization = dbconnect.InitializeDB();
	dbconnect.m_Connection = dbconnect.ConnectDB(dbconninitialization, "localhost", "root", "Nadim@144", "OC_Assignment", 3306);
	if (dbconnect.m_Connection)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CUserLogin::login(CString URole, CString UName, CString UPassword)
{
	bool flag = false;
	std::string query = "SELECT *  FROM _user";
	const char* q = query.c_str();
	dbconnect.querystate = mysql_query(dbconnect.m_Connection, q);

	if (!dbconnect.querystate)
	{
		dbconnect.m_Res = mysql_store_result(dbconnect.m_Connection);

		while (dbconnect.m_Row = mysql_fetch_row(dbconnect.m_Res))
		{
			std::string id = dbconnect.m_Row[0];
			std::string userrole = dbconnect.m_Row[1];
			std::string username = dbconnect.m_Row[2];
			std::string userpasswrod = dbconnect.m_Row[3];

			CString UserRole(userrole.c_str());
			CString UserName(username.c_str());
			CString UserPassword(userpasswrod.c_str());
			
			if (URole.Compare(UserRole) == 0)
			{
				if (UName.Compare(UserName) == 0)
				{
					if (UPassword.Compare(UserPassword) == 0)
					{
						m_UserRole = URole;
						m_UserName = UName;
						m_UserPassword = UPassword;
						flag = true;
						return flag;
					}
					else
					{
						flag = false;
					}
				}
			}
			else
			{
				continue;
			}
		}
	}
	else
	{
		flag = false;
	}

	return flag;
}

CString CUserLogin::GetUsername()
{
	return m_UserName +_T("@cerner.com");
}

CString CUserLogin::GetUserrole()
{
	return m_UserRole;
}

// Destructor
CUserLogin::~CUserLogin()
{

}