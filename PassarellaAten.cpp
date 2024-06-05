#include "pch.h"
#include "PassarellaAten.h"
#include "DBConnection.h"

using namespace System::Collections::Generic;
using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms;

PassarellaAten^ PassarellaAten::crear(String^ _tipus, int^ _idcentre)
{

    MySqlConnection^ conn = (gcnew DBConnection())->getConnection(); // <-- Declaraci�

    String^ sql = "INSERT INTO aten (nom_tipus, numeroid_centre) VALUES (@tipus, @idcentre)";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    // Establecer los par�metros de la consulta con los valores proporcionados
    cmd->Parameters->AddWithValue("@tipus", _tipus);
    cmd->Parameters->AddWithValue("@idcentre", _idcentre);

    try {
        // obrim la connexi�
        conn->Open();
        cmd->ExecuteNonQuery();

    }
    catch (Exception^ ex) {
        // codi per mostrar l�error en una finestra
        MessageBox::Show("Error al insertar la aten en la base de datos: " + ex->Message);
    }
    finally {
        // si tot va b� es tanca la connexi�
        conn->Close();
    }
    return gcnew PassarellaAten(_tipus, _idcentre);

}

PassarellaAten::PassarellaAten(String^ _tipus, int^ _idcentre)
{
    _tipus = tipus;
    _idcentre = idcentre;

}

