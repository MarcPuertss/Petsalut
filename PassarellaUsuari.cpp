
#include "pch.h"
#include "PassarellaUsuari.h"
#include "DBConnection.h" 

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms; //Per mostrar MessageBox::Show una caixa amb el missatge d'error

PassarellaUsuari::PassarellaUsuari() : PassarellaUsuari("", "", "", "", "", "", "") {}

PassarellaUsuari::PassarellaUsuari(String^ _username, String^ _nom, String^ _contrasenya, String^ _correu, String^ _telefon, String^ _tipus, String^ _descripcio)
{
    username = _username;
    nom = _nom;
    contrasenya = _contrasenya;
    correu = _correu;
    telefon = _telefon;
    tipus = _tipus;
    descripcio = _descripcio;

}

PassarellaUsuari::PassarellaUsuari(const PassarellaUsuari^ u)
{
    this->username = u->username;
    this->nom = u->nom;
    this->contrasenya = u->contrasenya;
    this->correu = u->correu;
    this->telefon = u->telefon;
    this->tipus = u->tipus;
    this->descripcio = u->descripcio;

}

void PassarellaUsuari::crear()
{
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

    String^ sql = "SELECT * FROM usuari WHERE username = @username";
    String^ sql1 = "SELECT * FROM usuari WHERE correu_electronic = @correu_electronic";
    String^ sql2 = "SELECT * FROM usuari WHERE telefon = @telefon";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
    MySqlCommand^ cmd1 = gcnew MySqlCommand(sql1, conn);
    MySqlCommand^ cmd2 = gcnew MySqlCommand(sql2, conn);

    cmd->Parameters->AddWithValue("@username", username);
    cmd1->Parameters->AddWithValue("@correu_electronic", correu);
    cmd2->Parameters->AddWithValue("@telefon", telefon);

    conn->Open();
    MySqlDataReader^ dataReader = cmd->ExecuteReader();

    if (dataReader->Read()) {
        conn->Close();
        throw gcnew Exception("Aquest nom d'usuari ja existeix, prova amb un de diferent");
    }

    dataReader->Close(); // Cerrar el primer DataReader después de su uso

    dataReader = cmd1->ExecuteReader();

    if (dataReader->Read()) {
        conn->Close();
        throw gcnew Exception("Aquest correu electronic ja te un usuari associat");
    }

    dataReader->Close(); // Cerrar el segundo DataReader después de su uso

    dataReader = cmd2->ExecuteReader();

    if (dataReader->Read()) {
        conn->Close();
        throw gcnew Exception("Aquest telefon ja te un usuari associat");
    }

    dataReader->Close(); // Cerrar el tercer DataReader después de su uso

    try {
        String^ sql0 = "INSERT INTO usuari VALUES (@username, @contrasenya, @nom, @correu_electronic, @telefon, @descripcio, @tipus);";
        MySqlCommand^ cmd0 = gcnew MySqlCommand(sql0, conn);
        cmd0->Parameters->AddWithValue("@username", username);
        cmd0->Parameters->AddWithValue("@contrasenya", contrasenya);
        cmd0->Parameters->AddWithValue("@nom", nom);
        cmd0->Parameters->AddWithValue("@telefon", telefon);
        cmd0->Parameters->AddWithValue("@tipus", tipus);
        cmd0->Parameters->AddWithValue("@correu_electronic", correu);
        cmd0->Parameters->AddWithValue("@descripcio", descripcio);

        cmd0->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Hi ha hagut un error al registrar el usuari");
    }
    finally {
        conn->Close();
    }
}

void PassarellaUsuari::esborra(String^ contrasenyaU) {

    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

    try {

        String^ sql = "DELETE FROM usuari WHERE @username = username AND @contrasenya = contrasenya";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

        cmd->Parameters->AddWithValue("@username", username);
        cmd->Parameters->AddWithValue("@contrasenya", contrasenyaU);

        conn->Open();
        cmd->ExecuteNonQuery();
        conn->Close();

    }
    catch (Exception^ ex) {
        throw gcnew Exception("La contrasenya es incorrecta, no s'eliminara l'usuari");
    
    }

}

String^ PassarellaUsuari::getNom()
{
    return nom;
}

String^ PassarellaUsuari::getUsername()
{
    return username;
}

String^ PassarellaUsuari::getContrasenya()
{
    return contrasenya;
}

String^ PassarellaUsuari::getTipus()
{
    return tipus->ToString();
}

String^ PassarellaUsuari::getCorreuElectronic()
{
    return correu;
}

String^ PassarellaUsuari::getDescripcio()
{
    return descripcio;
}

String^ PassarellaUsuari::getTelefon()
{
    return telefon;
}


void PassarellaUsuari::setNom(String^ nuevoNom)
{
    nom = nuevoNom;
}

void PassarellaUsuari::setUsername(String^ nuevoUsername)
{
    username = nuevoUsername;
}

void PassarellaUsuari::setContrasenya(String^ nuevaContrasenya)
{
    contrasenya = nuevaContrasenya;
}

void PassarellaUsuari::setTipus(String^ nouTipus)
{
    tipus = nouTipus;
}

void PassarellaUsuari::setCorreuElectronic(String^ nuevoCorreuElectronic)
{
    correu = nuevoCorreuElectronic;
}

void PassarellaUsuari::setDescripcio(String^ nuevaDescripcion)
{
    descripcio = nuevaDescripcion;
}

void PassarellaUsuari::setTelefon(String^ nuevoTelefono)
{
    telefon = nuevoTelefono;
}
