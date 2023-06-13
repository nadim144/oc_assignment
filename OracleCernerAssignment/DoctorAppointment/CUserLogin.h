
#pragma once
#include "CDatabaseConnect.h"

class CUserLogin
{
public:
	CString m_UserRole;
	CString m_UserName;
	CString m_UserPassword;
	CDatabaseConnect dbconnect;
	int diff;
public:
	CUserLogin();
	~CUserLogin();
	bool dbconnectioncheck();
	bool login(CString URole, CString UName, CString UPassword);
	CString GetUserrole();
	CString GetUsername();

};

