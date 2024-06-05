#include "pch.h"
#include "CercadoraAten.h"
#include "PassarellaAten.h"
#include "DBConnection.h" 



List<String^>^ CercadoraAten::cercaTipusAten(int id)
{
    List<String^>^ tipusList = gcnew List<String^>();

    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

    String^ sql = "SELECT * FROM aten WHERE numeroid_centre = @numeroid_centre;";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    cmd->Parameters->AddWithValue("@numeroid_centre", id);

    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read()) {
            String^ tipus = reader["nom_tipus"]->ToString();
            tipusList->Add(tipus);
        }

        reader->Close();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Hi ha hagut un error amb el aten" + ex->Message);
    }
    finally {
        conn->Close();
    }

    return tipusList;
}

List<int>^ CercadoraAten::cercaCentreIdsPerTipus(String^ tipus) {
    List<int>^ centreIds = gcnew List<int>();

    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();
    String^ sql = "SELECT numeroid_centre FROM aten WHERE nom_tipus = @tipus;";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
    cmd->Parameters->AddWithValue("@tipus", tipus);

    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read()) {
            int centreId = reader->GetInt32("numeroid_centre");
            centreIds->Add(centreId);
        }

        reader->Close();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Error en la búsqueda de centres: " + ex->Message);
    }
    finally {
        conn->Close();
    }

    return centreIds;
}