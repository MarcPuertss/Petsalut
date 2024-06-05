#include "pch.h"
#include "DBConnection.h" 
#include "PassarellaClinica.h"
#include "CercadoraClinica.h"

using namespace System;

PassarellaClinica^ CercadoraClinica::cercaClinica(String^ usernameU)
{
	MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

	String^ sql = "SELECT * FROM clinica WHERE username = @username";

	MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

	cmd->Parameters->AddWithValue("@username", usernameU);

	PassarellaClinica^ cli;
	MySqlDataReader^ dataReader;

	try {

		conn->Open();
		dataReader = cmd->ExecuteReader();
		if (dataReader->Read()) {
			cli = gcnew PassarellaClinica(usernameU);
		}
	}

	catch (Exception^ ex) {

		throw gcnew Exception("Hi ha hagut un error amb el nom d'usuari o la contrasenya");
	}

	finally {

		conn->Close();
	}

	return cli;
}