#include "pch.h"
#include "PassarellaParticipa.h"
#include "DBConnection.h"

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms; // Para mostrar MessageBox::Show una caja con el mensaje de error

PassarellaParticipa::PassarellaParticipa() : PassarellaParticipa(0, "") {}

PassarellaParticipa::PassarellaParticipa(int _numeroid, String^ _username)
{
    numeroid = _numeroid;
    username = _username;
}

PassarellaParticipa::PassarellaParticipa(const PassarellaParticipa^ p)
{
    this->numeroid = p->numeroid;
    this->username = p->username;
}

void PassarellaParticipa::crear()
{
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

    try {
        // Especificar las columnas numeroid y username explícitamente
        String^ sql0 = "INSERT INTO participa (numeroid, username) VALUES (@numeroid, @username);";
        MySqlCommand^ cmd0 = gcnew MySqlCommand(sql0, conn);
        cmd0->Parameters->AddWithValue("@numeroid", numeroid);
        cmd0->Parameters->AddWithValue("@username", username);
        conn->Open();
        cmd0->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        conn->Close();
    }
}

void PassarellaParticipa::eliminar()
{
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

    try {
        // Definir la consulta SQL para eliminar la fila
        String^ sql = "DELETE FROM participa WHERE numeroid = @numeroid AND username = @username;";

        // Crear y configurar el comando SQL
        MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
        cmd->Parameters->AddWithValue("@numeroid", numeroid);
        cmd->Parameters->AddWithValue("@username", username);

        // Abrir la conexión y ejecutar el comando
        conn->Open();
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        // Manejar cualquier excepción lanzada y relanzarla
        throw ex;
    }
    finally {
        // Asegurarse de que la conexión se cierre, independientemente de si ocurre una excepción o no
        conn->Close();
    }
}

