#include "pch.h"
#include "PassarellaVisites.h"
#include "DBConnection.h"
#include <string>

using namespace System::Collections::Generic;
using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms;

PassarellaVisites^ PassarellaVisites::crear(int _numero_id, int _mascota, int _centre)
{
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

    String^ sql = "INSERT INTO privat (numero_id, mascota, centre) VALUES (@numero_id, @mascota, @centre)";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    // Establecer los parámetros de la consulta con los valores proporcionados
    cmd->Parameters->AddWithValue("@numero_id", _numero_id);
    cmd->Parameters->AddWithValue("@mascota", _mascota);
    cmd->Parameters->AddWithValue("@centre", _centre);
    
    try {
        conn->Open();
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error al insertar la visita en la base de datos: " + ex->Message);
    }
    finally {
        conn->Close();
    }
    return gcnew PassarellaVisites(_numero_id, _mascota, _centre);
}


PassarellaVisites^ PassarellaVisites::eliminar(int numero_id)
{
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

    // Consulta para seleccionar y luego eliminar la visita
    String^ sqlSelectVisita = "SELECT * FROM privat WHERE numero_id = @numero_id";
    String^ sqlDeleteVisita = "DELETE FROM privat WHERE numero_id = @numero_id";

    // Consulta para eliminar el evento asociado
    String^ sqlDeleteEsdeveniment = "DELETE FROM esdeveniment WHERE numeroid = @numero_id";

    MySqlCommand^ cmdSelectVisita = gcnew MySqlCommand(sqlSelectVisita, conn);
    MySqlCommand^ cmdDeleteVisita = gcnew MySqlCommand(sqlDeleteVisita, conn);
    MySqlCommand^ cmdDeleteEsdeveniment = gcnew MySqlCommand(sqlDeleteEsdeveniment, conn);

    cmdSelectVisita->Parameters->AddWithValue("@numero_id", numero_id);
    cmdDeleteVisita->Parameters->AddWithValue("@numero_id", numero_id);
    cmdDeleteEsdeveniment->Parameters->AddWithValue("@numero_id", numero_id);

    PassarellaVisites^ visitaEliminada = nullptr;

    try {
        conn->Open();

        // Ejecutar la selección de la visita
        MySqlDataReader^ reader = cmdSelectVisita->ExecuteReader();
        if (reader->Read()) {
            int id = reader->GetInt32("numero_id");
            int mascota = reader->GetInt32("mascota");
            int centre = reader->GetInt32("centre");

            visitaEliminada = gcnew PassarellaVisites(id, mascota, centre);
        }
        reader->Close();

        // Eliminar la visita
        cmdDeleteVisita->ExecuteNonQuery();

        // Eliminar el evento asociado
        cmdDeleteEsdeveniment->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error al eliminar la visita y el evento de la base de datos: " + ex->Message);
    }
    finally {
        conn->Close();
    }

    return visitaEliminada;
}


PassarellaVisites::PassarellaVisites(int _numero_id, int _mascota, int _centre) {
    numero_id = _numero_id;
    mascota = _mascota;
    centre = _centre;
}
