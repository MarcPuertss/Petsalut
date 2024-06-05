#include "pch.h"
#include "TxModUsu.h"
#include "PasswordEncrypt.h"

void TxModUsu::crear(String^ usernameS, String^ contrasenyaS, String^ nomComplertS, String^ telefonS, String^ dataS, String^ correuElectronicS, String^ descripcioS, String^ tipusS)
{
    
    _username = usernameS;

    _contrasenya =  PasswordEncrypt::Encrypt(contrasenyaS);

    _nomComplert = nomComplertS;
    _telefon = telefonS;
    _data = dataS;
    _correuElectronic = correuElectronicS;
    _descripcio = descripcioS;
    _tipus = tipusS;

}

void TxModUsu::executar()
{
    
    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

    // Comprobar si el nuevo correo electrónico ya está asociado a otro usuario
    String^ sql1 = "SELECT * FROM usuari WHERE correu_electronic = @correu AND username != @username";
    MySqlCommand^ cmd1 = gcnew MySqlCommand(sql1, conn);
    cmd1->Parameters->AddWithValue("@correu", _correuElectronic);
    cmd1->Parameters->AddWithValue("@username", _username);

    // Comprobar si el nuevo teléfono ya está asociado a otro usuario
    String^ sql2 = "SELECT * FROM usuari WHERE telefon = @telefon AND username != @username";
    MySqlCommand^ cmd2 = gcnew MySqlCommand(sql2, conn);
    cmd2->Parameters->AddWithValue("@telefon", _telefon);
    cmd2->Parameters->AddWithValue("@username", _username);

    try {
        conn->Open();

        MySqlDataReader^ dataReader1 = cmd1->ExecuteReader();
        if (dataReader1->Read()) {
            conn->Close();
            dataReader1->Close();
            throw gcnew Exception("Aquest correu electronic ja te un altre usuari associat");
        }
        dataReader1->Close();

        MySqlDataReader^ dataReader2 = cmd2->ExecuteReader();
        if (dataReader2->Read()) {
            conn->Close();
            dataReader2->Close();
            throw gcnew Exception("Aquest telefon ja te un altre usuari associat");
        }
        dataReader2->Close();

        // Realizar la modificació del propietari
        String^ sql0 = "UPDATE usuari SET contrasenya = @contrasenya, nom = @nom, correu_electronic = @correu, telefon = @telefon, descripcio = @descripcio WHERE username = @username";
        MySqlCommand^ cmd0 = gcnew MySqlCommand(sql0, conn);
        cmd0->Parameters->AddWithValue("@username", _username);
        cmd0->Parameters->AddWithValue("@contrasenya", _contrasenya);
        cmd0->Parameters->AddWithValue("@nom", _nomComplert);
        cmd0->Parameters->AddWithValue("@telefon", _telefon);
        cmd0->Parameters->AddWithValue("@correu", _correuElectronic);
        cmd0->Parameters->AddWithValue("@descripcio", _descripcio);

        cmd0->ExecuteNonQuery();

        if (_tipus == "propietari") {
            String^ sql3 = "UPDATE propietari SET data_naixement = @data_naixement WHERE username = @username";
            MySqlCommand^ cmd3 = gcnew MySqlCommand(sql3, conn);
            cmd3->Parameters->AddWithValue("@username", _username);
            cmd3->Parameters->AddWithValue("@data_naixement", _data);
            cmd3->ExecuteNonQuery();
        }

    }
    catch (Exception^ ex) {
        //throw gcnew Exception("Hi ha hagut un error al modificar el usuari");
        throw ex;
    }
    finally {
        conn->Close();
    }

}
