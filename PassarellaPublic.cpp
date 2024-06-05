#include "pch.h"
#include "PassarellaPublic.h"

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms; //Per mostrar MessageBox::Show una caixa amb el missatge d'error

PassarellaPublic::PassarellaPublic() : PassarellaPublic("", 0,"","") {}

PassarellaPublic::PassarellaPublic(String^ _tipus, int _numeroid, String^ _descripcio, String^ _ubicacio)
{

    tipus = _tipus;
    numeroid = _numeroid;
    descripcio = _descripcio;
    ubicacio = _ubicacio;

}

PassarellaPublic::PassarellaPublic(const PassarellaPublic^ p)
{
    this->tipus = p->tipus;
    this->numeroid = p->numeroid;
    this->descripcio = p->descripcio;
    this->ubicacio = p->ubicacio;
}

void PassarellaPublic::crear()
{
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

    try {
        // Especificar las columnas numeroid y tipus explícitamente
        String^ sql0 = "INSERT INTO public (numeroid, tipus, descripcio, ubicacio) VALUES (@numeroid, @tipus, @descripcio, @ubicacio);";
        MySqlCommand^ cmd0 = gcnew MySqlCommand(sql0, conn);
        cmd0->Parameters->AddWithValue("@numeroid", numeroid);
        cmd0->Parameters->AddWithValue("@tipus", tipus);
        cmd0->Parameters->AddWithValue("@descripcio", descripcio);
        cmd0->Parameters->AddWithValue("@ubicacio", ubicacio);
        conn->Open();
        cmd0->ExecuteNonQuery();

        // Obtener el ID generado automáticamente
        MySqlCommand^ cmd1 = gcnew MySqlCommand("SELECT `index` FROM public WHERE numeroid = @numeroid;", conn);
        cmd1->Parameters->AddWithValue("@numeroid", numeroid);
        MySqlDataReader^ reader = cmd1->ExecuteReader();
        if (reader->Read()) {
            int generatedIndex = reader->GetInt32(0); // Guardar el ID autoincremental generado
            // Puedes usar generatedIndex si necesitas realizar alguna operación adicional
        }
        reader->Close();
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        conn->Close();
    }
}