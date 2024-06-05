#include "pch.h"
#include "CercadoraParticipa.h"
#include "DBConnection.h"

using namespace System;

PassarellaParticipa^ CercadoraParticipa::cercaParticipa(int numeroid, String^ usernameU)
{
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();
    String^ sql = "SELECT * FROM participa WHERE numeroid = @numeroid AND username = @username";
    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
    cmd->Parameters->AddWithValue("@numeroid", numeroid);
    cmd->Parameters->AddWithValue("@username", usernameU);

    PassarellaParticipa^ participa;
    MySqlDataReader^ dataReader;

    try {
        conn->Open();
        dataReader = cmd->ExecuteReader();

        if (dataReader->Read()) {
            // Leer los valores necesarios de la consulta
            int readNumeroid = dataReader->GetInt32("numeroid");
            String^ readUsername = dataReader->GetString("username");

            participa = gcnew PassarellaParticipa(readNumeroid, readUsername);
        }
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Hi ha hagut un error amb el numeroid o el nom d'usuari");
    }
    finally {
        conn->Close();
    }

    return participa;
}

int CercadoraParticipa::cuantosParticipa(int numeroid)
{
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();
    String^ sql = "SELECT COUNT(*) FROM participa WHERE numeroid = @numeroid";
    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
    cmd->Parameters->AddWithValue("@numeroid", numeroid);

    int count = 0;

    try {
        conn->Open();
        Object^ result = cmd->ExecuteScalar(); // ExecuteScalar se usa para obtener un valor único
        if (result != nullptr) {
            count = Convert::ToInt32(result);
        }
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Hi ha hagut un error en comptar els participants");
    }
    finally {
        conn->Close();
    }

    return count;
}
