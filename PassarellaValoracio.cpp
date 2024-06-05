#include "pch.h"
#include "PassarellaValoracio.h"
#include "DBConnection.h" // Importación necesaria

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms; // Para mostrar MessageBox::Show

PassarellaValoracio^ PassarellaValoracio::crear(int _numeroid_centre, int _numeroid_privat, String^ _propietari, int _valor)
{
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection(); // Declaración

    String^ sql = "INSERT INTO valoracio (numeroid_privat, numeroid_centre, propietari, valor) VALUES (@numeroid_privat, @numeroid_centre, @propietari, @valor)";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    // Establecer los parámetros de la consulta con los valores proporcionados
    cmd->Parameters->AddWithValue("@numeroid_centre", _numeroid_centre);
    cmd->Parameters->AddWithValue("@numeroid_privat", _numeroid_privat);
    cmd->Parameters->AddWithValue("@propietari", _propietari);
    cmd->Parameters->AddWithValue("@valor", _valor);

    try {
        // Abrir la conexión
        conn->Open();
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        // Mostrar mensaje de error
        MessageBox::Show("Error al insertar la valoración en la base de datos: " + ex->Message);
    }
    finally {
        // Cerrar la conexión
        conn->Close();
    }

    return gcnew PassarellaValoracio(_numeroid_centre, _numeroid_privat, _propietari, _valor);
}

PassarellaValoracio^ PassarellaValoracio::modificar(int _numeroid_centre, int _numeroid_privat, String^ _propietari, int _valor)
{
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection(); // Declaración

    String^ sql = "UPDATE valoracio SET propietari = @propietari, valor = @valor WHERE numeroid_centre = @numeroid_centre AND numeroid_privat = @numeroid_privat";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    // Establecer los parámetros de la consulta con los valores proporcionados
    cmd->Parameters->AddWithValue("@numeroid_centre", _numeroid_centre);
    cmd->Parameters->AddWithValue("@numeroid_privat", _numeroid_privat);
    cmd->Parameters->AddWithValue("@propietari", _propietari);
    cmd->Parameters->AddWithValue("@valor", _valor);

    try {
        // Abrir la conexión
        conn->Open();
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        // Mostrar mensaje de error
        MessageBox::Show("Error al modificar la valoración en la base de datos: " + ex->Message);
    }
    finally {
        // Cerrar la conexión
        conn->Close();
    }

    return gcnew PassarellaValoracio(_numeroid_centre, _numeroid_privat, _propietari, _valor);
}

PassarellaValoracio^ PassarellaValoracio::eliminar(int _numeroid_centre, int _numeroid_privat)
{
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection(); // Declaración

    String^ sql = "DELETE FROM valoracio WHERE numeroid_centre = @numeroid_centre AND numeroid_privat = @numeroid_privat";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    // Establecer los parámetros de la consulta con los valores proporcionados
    cmd->Parameters->AddWithValue("@numeroid_centre", _numeroid_centre);
    cmd->Parameters->AddWithValue("@numeroid_privat", _numeroid_privat);

    try {
        // Abrir la conexión
        conn->Open();
        cmd->ExecuteNonQuery(); // Ejecutar la consulta para eliminar la valoración
    }
    catch (Exception^ ex) {
        // Manejar cualquier excepción y mostrar un mensaje de error
        MessageBox::Show("Error al eliminar la valoración de la base de datos: " + ex->Message);
    }
    finally {
        // Cerrar la conexión independientemente de si hubo un error o no
        conn->Close();
    }

    // No necesitamos devolver nada, ya que estamos eliminando la valoración
    return nullptr;
}

PassarellaValoracio::PassarellaValoracio(int _numeroid_centre, int _numeroid_privat, String^ _propietari, int _valor) {
    numeroid_centre = _numeroid_centre;
    numeroid_privat = _numeroid_privat;
    propietari = _propietari;
    valor = _valor;
}
