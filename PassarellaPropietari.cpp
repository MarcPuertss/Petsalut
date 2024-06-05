#include "pch.h"
#include "PassarellaPropietari.h"
#include "DBConnection.h" 

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms; //Per mostrar MessageBox::Show una caixa amb el missatge d'error

PassarellaPropietari::PassarellaPropietari() : PassarellaPropietari("", "") {}

PassarellaPropietari::PassarellaPropietari(String^ _data_naixament, String^ _username)
{

    data_naixament = _data_naixament;
    username = _username;

}

PassarellaPropietari::PassarellaPropietari(const PassarellaPropietari^ p)
{
    this->data_naixament = p->data_naixament;
    this->username = p->username;
}

void PassarellaPropietari::crear()
{
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

    try {
        String^ sql0 = "INSERT INTO propietari VALUES (@username, @data_naixement);";
        MySqlCommand^ cmd0 = gcnew MySqlCommand(sql0, conn);
        cmd0->Parameters->AddWithValue("@username", username);
        cmd0->Parameters->AddWithValue("@data_naixement", data_naixament);
        conn->Open();
        cmd0->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        //throw gcnew Exception("Hi ha hagut un error al registrar el propietari");
        throw ex;
    }
    finally {
        conn->Close();
    }
}

String^ PassarellaPropietari::getDataNaixement()
{
    return data_naixament;
}


String^ PassarellaPropietari::getUsername()
{
    return username;
}

void PassarellaPropietari::setDataNaixement(String^ nuevaDataNaixement)
{
    data_naixament = nuevaDataNaixement;
}

void PassarellaPropietari::setUsername(String^ nuevoUsername)
{
    username = nuevoUsername;
}

vector<int> PassarellaPropietari::obtenerMascotas()
{


    vector<int> chips;
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();
    String^ sql = "SELECT chip FROM mascota WHERE propietari = @propietari;";
    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
    cmd->Parameters->AddWithValue("@propietari", this->username);

    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read()) {
            int chip = Convert::ToInt32(reader["chip"]);
            chips.push_back(chip);
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

    return chips;
}