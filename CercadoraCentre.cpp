#include "pch.h"
#include "CercadoraCentre.h"
#include "DBConnection.h" 

using namespace System::Collections::Generic;


PassarellaCentre^ CercadoraCentre::cercaCentre(int numero_ID)
{
    PassarellaCentre^ centreTrobat = gcnew PassarellaCentre();

    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

    String^ sql = "SELECT * FROM centre WHERE numero_ID = @numero_ID";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    cmd->Parameters->AddWithValue("@numero_ID", numero_ID);

    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        if (reader->Read()) {
            int _numero_ID = Convert::ToInt32(reader["numero_ID"]);
            String^ _nom = reader["nom"]->ToString();
            String^ _telefon = reader["telefon"]->ToString();
            String^ _clinica = reader["clinica"]->ToString();
            String^ _ubicacio = reader["ubicacio"]->ToString();

            centreTrobat = gcnew PassarellaCentre(numero_ID, _nom, _telefon, _clinica, _ubicacio);
        }

        reader->Close();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Hi ha hagut un error amb el numero de identificació");
    }
    finally {
        conn->Close();
    }

    return centreTrobat;
}
List<PassarellaCentre^>^ CercadoraCentre::CercatotsCentres() {
    List<PassarellaCentre^>^ totsCentres = gcnew List<PassarellaCentre^>();

    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();
    String^ sql = "SELECT * FROM centre"; // Consulta para obtener todos los centros

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        // Leer todos los registros obtenidos
        while (reader->Read()) {
            int _numero_ID = Convert::ToInt32(reader["numero_ID"]);
            String^ _nom = reader["nom"]->ToString();
            String^ _telefon = reader["telefon"]->ToString();
            String^ _clinica = reader["clinica"]->ToString();
            String^ _ubicacio = reader["ubicacio"]->ToString();

            PassarellaCentre^ centre = gcnew PassarellaCentre(_numero_ID, _nom, _telefon, _clinica, _ubicacio);
            totsCentres->Add(centre); // Agregar cada centro a la lista
        }

        reader->Close();
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error al obtener centros: " + ex->Message);
        throw gcnew Exception("Error al consultar todos los centros.");
    }
    finally {
        if (conn != nullptr) {
            conn->Close();
        }
    }

    return totsCentres;
}

