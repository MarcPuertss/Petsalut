
#include "pch.h"
#include "CercadoraUsuari.h"
#include "DBConnection.h" 

using namespace System;

PassarellaUsuari^ CercadoraUsuari::cercaUsuari(String^ usernameU)
{

	MySqlConnection^ conn = (gcnew DBConnection())->getConnection();
	String^ sql = "SELECT * FROM usuari WHERE username = @username";
	MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
	cmd->Parameters->AddWithValue("@username", usernameU);

	PassarellaUsuari^ usu;
	MySqlDataReader^ dataReader;

	try {

		conn->Open();
		dataReader = cmd->ExecuteReader();

		if (dataReader->Read()) {

			String^ username = dataReader->GetString(0);
			String^ contrasenya = dataReader->GetString(1);
			String^ nom = dataReader->GetString(2);
			String^ correu = dataReader->GetString(3);
			String^ telefon = dataReader->GetString(4);
			String^ descripcio = dataReader->GetString(5);
			String^ tipus = dataReader->GetString(6);
			

			usu = gcnew PassarellaUsuari(username, nom, contrasenya, correu, telefon, tipus, descripcio);

		}

	}

	catch (Exception^ ex) {

		throw gcnew Exception("Hi ha hagut un error amb el nom d'usuari o la contrasenya");

	}

	finally {

		conn->Close();
	}

	return usu;

}
