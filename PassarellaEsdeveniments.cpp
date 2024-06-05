#include "pch.h"
#include "PassarellaEsdeveniments.h"
#include "DBConnection.h" 

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms;


void PassarellaEsdeveniments::crear() {
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

    String^ sql = "INSERT INTO esdeveniment (numeroid, nom, data, hora, propietari, tipus) VALUES (@numeroid, @nom, @data, @hora, @propietari, @tipus)";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    // Establecer los parámetros de la consulta con los valores proporcionados
    cmd->Parameters->AddWithValue("@numeroid", numeroid);
    cmd->Parameters->AddWithValue("@nom", nom);
    cmd->Parameters->AddWithValue("@data", data);
    cmd->Parameters->AddWithValue("@hora", hora);
    cmd->Parameters->AddWithValue("@propietari", propietari);
    cmd->Parameters->AddWithValue("@tipus", tipus);


    try {
        conn->Open();
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error al insertar el esdeveniment en la base de datos: " + ex->Message);
    }
    finally {
        conn->Close();
    }
}



void PassarellaEsdeveniments::eliminar() {

    MySqlConnection^ conn = (gcnew DBConnection())->getConnection(); // <-- Declaraci�

    String^ sql = "DELETE FROM esdeveniment WHERE numeroid = @numeroid";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    // Establecer el parámetro de la consulta con el valor proporcionado
    cmd->Parameters->AddWithValue("@numeroid", numeroid);

    try {
        conn->Open();
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error al eliminar el esdeveniment de la base de datos: " + ex->Message);
    }
    finally {
        conn->Close();
    }

}
PassarellaEsdeveniments::PassarellaEsdeveniments(int _numeroid, String^ _nom, DateTime _data, String^ _hora, String^ _propietari, String^ _tipus) {

    numeroid = _numeroid;
    nom = _nom;
    data = _data;
    hora = _hora;
    propietari = _propietari;
    tipus = _tipus;
}