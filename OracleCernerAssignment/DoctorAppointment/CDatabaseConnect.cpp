#include "pch.h"
#include "CDatabaseConnect.h"


//Default Constructor
CDatabaseConnect::CDatabaseConnect() :  querystate(0),
										m_Connection(nullptr),
										m_Res(nullptr)
{
	//Default Constructor
}

//Default Destructor
CDatabaseConnect::~CDatabaseConnect()
{
	//Default Destructor
}

MYSQL* CDatabaseConnect::InitializeDB()
{
	MYSQL* initializationState = mysql_init(0);
	return initializationState;
}

MYSQL* CDatabaseConnect::ConnectDB(MYSQL* conn, std::string server, std::string dbuser, std::string dbpassword, std::string dbname, int dbport)
{
	MYSQL* DBConnState = mysql_real_connect(conn, 
											server.c_str(), 
											dbuser.c_str(), 
											dbpassword.c_str(), 
											dbname.c_str(), 
											dbport, 
											NULL, 
											0);
	return DBConnState;
}


