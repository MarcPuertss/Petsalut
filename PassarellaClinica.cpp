#include "pch.h"
#include "PassarellaClinica.h"
#include "DBConnection.h" 

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms; //Per mostrar MessageBox::Show una caixa amb el missatge d'error

PassarellaClinica^ PassarellaClinica::crear()
{

	MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

	String^ sql = "INSERT INTO clinica (username) VALUES (@username);";

	MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

	// Establecer los parámetros de la consulta con los valores proporcionados
	cmd->Parameters->AddWithValue("@username", username);
	try {
		// obrim la connexió
		conn->Open();
		cmd->ExecuteNonQuery();
	}
	catch (Exception^ ex) {
		// codi per mostrar l'error en una finestra
		MessageBox::Show("Error al insertar la clinica en la base de datos: " + ex->Message);
	}
	finally {
		// si tot va bé es tanca la connexió
		conn->Close();
	}
	return gcnew PassarellaClinica(username);

}



PassarellaClinica::PassarellaClinica(String^ _username) {
	username = _username;
}

PassarellaClinica::PassarellaClinica(const PassarellaClinica^ p) {
	this->username = p->username;
}

List<int>^ PassarellaClinica::obtenirCentres()
{
    List<int>^ numeros_ID = gcnew List<int>();
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();
    String^ sql = "SELECT numero_ID FROM centre WHERE clinica = @clinica;";
    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
    cmd->Parameters->AddWithValue("@clinica", this->username);

    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read()) {
            int numero_ID = Convert::ToInt32(reader["numero_ID"]);
            numeros_ID->Add(numero_ID);
        }

        reader->Close();
    }
    catch (Exception^ ex) {
        // Manejar la excepción
        Console::WriteLine(ex->Message);
    }
    finally {
        conn->Close();
    }

    return numeros_ID;
}

