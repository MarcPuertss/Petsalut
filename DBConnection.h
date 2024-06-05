#pragma once

#include <iostream>
using namespace MySql::Data::MySqlClient;
using namespace std;

public ref class DBConnection
{
public:
	DBConnection();
	
	MySqlConnection^ getConnection();

private:
	MySqlConnection^ conn;
};
