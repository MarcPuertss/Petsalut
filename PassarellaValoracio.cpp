#include "pch.h"
#include "PassarellaValoracio.h"
#include "DBConnection.h" // Importaci�n necesaria

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms; // Para mostrar MessageBox::Show

PassarellaValoracio^ PassarellaValoracio::crear(int _numeroid_centre, int _numeroid_privat, String^ _propietari, int _valor)
{
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection(); // Declaraci�n

    String^ sql = "INSERT INTO valoracio (numeroid_privat, numeroid_centre, propietari, valor) VALUES (@numeroid_privat, @numeroid_centre, @propietari, @valor)";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    // Establecer los par�metros de la consulta con los valores proporcionados
    cmd->Parameters->AddWithValue("@numeroid_centre", _numeroid_centre);
    cmd->Parameters->AddWithValue("@numeroid_privat", _numeroid_privat);
    cmd->Parameters->AddWithValue("@propietari", _propietari);
    cmd->Parameters->AddWithValue("@valor", _valor);

    try {
        // Abrir la conexi�n
        conn->Open();
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        // Mostrar mensaje de error
        MessageBox::Show("Error al insertar la valoraci�n en la base de datos: " + ex->Message);
    }
    finally {
        // Cerrar la conexi�n
        conn->Close();
    }

    return gcnew PassarellaValoracio(_numeroid_centre, _numeroid_privat, _propietari, _valor);
}

PassarellaValoracio^ PassarellaValoracio::modificar(int _numeroid_centre, int _numeroid_privat, String^ _propietari, int _valor)
{
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection(); // Declaraci�n

    String^ sql = "UPDATE valoracio SET propietari = @propietari, valor = @valor WHERE numeroid_centre = @numeroid_centre AND numeroid_privat = @numeroid_privat";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    // Establecer los par�metros de la consulta con los valores proporcionados
    cmd->Parameters->AddWithValue("@numeroid_centre", _numeroid_centre);
    cmd->Parameters->AddWithValue("@numeroid_privat", _numeroid_privat);
    cmd->Parameters->AddWithValue("@propietari", _propietari);
    cmd->Parameters->AddWithValue("@valor", _valor);

    try {
        // Abrir la conexi�n
        conn->Open();
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        // Mostrar mensaje de error
        MessageBox::Show("Error al modificar la valoraci�n en la base de datos: " + ex->Message);
    }
    finally {
        // Cerrar la conexi�n
        conn->Close();
    }

    return gcnew PassarellaValoracio(_numeroid_centre, _numeroid_privat, _propietari, _valor);
}

PassarellaValoracio^ PassarellaValoracio::eliminar(int _numeroid_centre, int _numeroid_privat)
{
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection(); // Declaraci�n

    String^ sql = "DELETE FROM valoracio WHERE numeroid_centre = @numeroid_centre AND numeroid_privat = @numeroid_privat";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    // Establecer los par�metros de la consulta con los valores proporcionados
    cmd->Parameters->AddWithValue("@numeroid_centre", _numeroid_centre);
    cmd->Parameters->AddWithValue("@numeroid_privat", _numeroid_privat);

    try {
        // Abrir la conexi�n
        conn->Open();
        cmd->ExecuteNonQuery(); // Ejecutar la consulta para eliminar la valoraci�n
    }
    catch (Exception^ ex) {
        // Manejar cualquier excepci�n y mostrar un mensaje de error
        MessageBox::Show("Error al eliminar la valoraci�n de la base de datos: " + ex->Message);
    }
    finally {
        // Cerrar la conexi�n independientemente de si hubo un error o no
        conn->Close();
    }

    // No necesitamos devolver nada, ya que estamos eliminando la valoraci�n
    return nullptr;
}

PassarellaValoracio::PassarellaValoracio(int _numeroid_centre, int _numeroid_privat, String^ _propietari, int _valor) {
    numeroid_centre = _numeroid_centre;
    numeroid_privat = _numeroid_privat;
    propietari = _propietari;
    valor = _valor;
}
