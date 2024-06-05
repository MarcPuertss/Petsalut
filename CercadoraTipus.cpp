#include "pch.h"
#include "DBConnection.h"
#include "CercadoraTipus.h"

using namespace System;
using namespace System::Collections::Generic;

List<String^>^ CercadoraTipus::obteTotsTipus()
{
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();
    String^ sql = "SELECT nom FROM tipus"; // Asumiendo que la tabla se llama 'tipus' y tiene una columna 'nom'
    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    List<String^>^ tipusList = gcnew List<String^>();
    MySqlDataReader^ dataReader;

    try {
        conn->Open();
        dataReader = cmd->ExecuteReader();
        while (dataReader->Read()) {
            String^ nom = dataReader["nom"]->ToString();
            tipusList->Add(nom);
        }
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Hi ha hagut un error en la cerca dels tipus");
    }
    finally {
        conn->Close();
    }

    return tipusList;
}
