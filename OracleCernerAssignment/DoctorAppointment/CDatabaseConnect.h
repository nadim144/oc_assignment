#pragma once
#include <mysql.h>
#include <iostream>


class CDatabaseConnect
{
public:
	MYSQL*		m_Connection;
	MYSQL_ROW	m_Row;
	MYSQL_RES*	m_Res;
	int			querystate;
public:
	CDatabaseConnect();
	~CDatabaseConnect();
	MYSQL* InitializeDB();
	MYSQL* ConnectDB(MYSQL* conn, std::string server, std::string dbuser, std::string dbpassword, 
		std::string dbname, int dbport );
};

