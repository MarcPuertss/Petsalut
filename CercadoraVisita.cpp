#include "pch.h"
#include "CercadoraVisita.h"
#include "DBConnection.h" 

using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;
using namespace System;

PassarellaVisites^ CercadoraVisita::cercaVisita(int numero_id) {
    PassarellaVisites^ visitaTrobada = nullptr;

    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();
    String^ sql = "SELECT * FROM privat WHERE numero_id = @numero_id";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
    cmd->Parameters->AddWithValue("@numero_id", numero_id);

    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        if (reader->Read()) {
            int _numero_id = Convert::ToInt32(reader["numero_id"]);
            int _mascota = Convert::ToInt32(reader["mascota"]);
            int _centre = Convert::ToInt32(reader["centre"]);

            visitaTrobada = gcnew PassarellaVisites(_numero_id, _mascota, _centre);
        }

        reader->Close();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Hi ha hagut un error amb el numero de identificació");
    }
    finally {
        conn->Close();
    }

    return visitaTrobada;
}

List<PassarellaVisites^>^ CercadoraVisita::cercaVisites(int centre)
{
    PassarellaVisites^ visitaTrobada = nullptr;

    List<PassarellaVisites^>^ visitesTrobades = gcnew List<PassarellaVisites^>();

    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();
    String^ sql = "SELECT * FROM privat WHERE centre = @centre";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
    cmd->Parameters->AddWithValue("@centre", centre);

    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read()) {
            int _numero_id = Convert::ToInt32(reader["numero_id"]);
            int _mascota = Convert::ToInt32(reader["mascota"]);
            int _centre = Convert::ToInt32(reader["centre"]);

            visitaTrobada = gcnew PassarellaVisites(_numero_id, _mascota, _centre);
            visitesTrobades->Add(visitaTrobada);
        }

        reader->Close();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Hi ha hagut un error amb el numero de identificació");
    }
    finally {
        conn->Close();
    }

    return visitesTrobades;
}
