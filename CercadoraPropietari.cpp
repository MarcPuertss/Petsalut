
#include "pch.h"
#include "CercadoraPropietari.h"
#include "DBConnection.h" 

using namespace System;

PassarellaPropietari^ CercadoraPropietari::cercaPropietari(String^ usernameU)
{

	MySqlConnection^ conn = (gcnew DBConnection())->getConnection();
	String^ sql = "SELECT * FROM propietari WHERE username = @username";
	MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
	cmd->Parameters->AddWithValue("@username", usernameU);

	PassarellaPropietari^ prop;
	MySqlDataReader^ dataReader;
	
	try {

		conn->Open();
		dataReader = cmd->ExecuteReader();

		if (dataReader->Read()) {

			String^ data = dataReader->GetString(1);

			prop = gcnew PassarellaPropietari(data, usernameU);

		}

	}

	catch (Exception^ ex) {

		throw gcnew Exception("Hi ha hagut un error amb el nom d'usuari o la contrasenya");
	}

	finally {

		conn->Close();
	}

	return prop;

}
