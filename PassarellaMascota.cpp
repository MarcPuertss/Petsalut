#include "pch.h"
#include "PassarellaMascota.h"
#include "DBConnection.h" // <-- Importaci�

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms;//Per mostrar MessageBox::Show una caixa amb el missatge d'error
PassarellaMascota^ PassarellaMascota::crear(int _chip, String^ _nom, DateTime _datanaixement, String^ _descripcio, String^ _propietari, String^ _tipus)
{

    MySqlConnection^ conn = (gcnew DBConnection())->getConnection(); // <-- Declaraci�

    String^ sql = "INSERT INTO mascota (chip, nom, datanaixement, descripcio, propietari, tipus) VALUES (@chip, @nom, @datanaixement, @descripcio, @propietari, @tipus)";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    // Establecer los par�metros de la consulta con los valores proporcionados
    cmd->Parameters->AddWithValue("@chip", _chip);
    cmd->Parameters->AddWithValue("@nom", _nom);
    cmd->Parameters->AddWithValue("@datanaixement", _datanaixement);
    cmd->Parameters->AddWithValue("@descripcio", _descripcio);
    cmd->Parameters->AddWithValue("@propietari", _propietari);
    cmd->Parameters->AddWithValue("@tipus", _tipus);

    try {
        // obrim la connexi�
        conn->Open();
        cmd->ExecuteNonQuery();

    }
    catch (Exception^ ex) {
        // codi per mostrar l�error en una finestra
        MessageBox::Show("Error al insertar la mascota en la base de datos: " + ex->Message);
    }
    finally {
        // si tot va b� es tanca la connexi�
        conn->Close();
    }
    return gcnew PassarellaMascota(_chip, _nom, _datanaixement, _descripcio, _propietari, _tipus);

}

PassarellaMascota^ PassarellaMascota::eliminar(int _chip) {

    MySqlConnection^ conn = (gcnew DBConnection())->getConnection(); // <-- Declaraci�

    String^ sql = "DELETE FROM mascota WHERE chip = @chip";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    // Establecer el parámetro de la consulta con el valor proporcionado
    cmd->Parameters->AddWithValue("@chip", _chip);

    try {
        // Abrir la conexión
        conn->Open();
        cmd->ExecuteNonQuery(); // Ejecutar la consulta para eliminar la mascota
    }
    catch (Exception^ ex) {
        // Manejar cualquier excepción y mostrar un mensaje de error
        MessageBox::Show("Error al eliminar la mascota de la base de datos: " + ex->Message);
    }
    finally {
        // Cerrar la conexión independientemente de si hubo un error o no
        conn->Close();
    }

    // No necesitamos devolver nada, ya que estamos eliminando la mascota, no creándola
    return nullptr;
}


PassarellaMascota::PassarellaMascota(int _chip, String^ _nom, DateTime _datanaixament, String^ _descripcio, String^ _propietari, String^ _tipus) {
    chip = _chip;
    nom = _nom;
    datanaixement = _datanaixament;
    descripcio = _descripcio;
    propietari = _propietari;
    tipus = _tipus;
}


vector<int> PassarellaMascota::obtenerVisites()
{
    vector<int> visites;
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();
    String^ sql = "SELECT numero_id FROM privat WHERE mascota = @mascota;";
    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
    cmd->Parameters->AddWithValue("@mascota", this->chip);

    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read()) {
            int numero_id = Convert::ToInt32(reader["numero_id"]);
            visites.push_back(numero_id);
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

    return visites;
}
