#include "pch.h"
#include "CercadoraMascota.h"
#include "DBConnection.h" 

PassarellaMascota^ CercadoraMascota::cercaMascota(int chip)
{
    PassarellaMascota^ mascotaEncontrada = nullptr;

    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

    String^ sql = "SELECT * FROM mascota WHERE chip = @chip";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    cmd->Parameters->AddWithValue("@chip", chip);

    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        if (reader->Read()) {
            // Si se encontró una mascota, crea un objeto PassarellaMascota con los datos obtenidos
            int _chip = Convert::ToInt32(reader["chip"]);
            String^ _nom = reader["nom"]->ToString();
            DateTime _datanaixement = Convert::ToDateTime(reader["datanaixement"]);
            String^ _descripcio = reader["descripcio"]->ToString();
            String^ _propietari = reader["propietari"]->ToString();
            String^ _tipus = reader["tipus"]->ToString();

            mascotaEncontrada = gcnew PassarellaMascota(_chip, _nom, _datanaixement, _descripcio, _propietari, _tipus);
        }

        reader->Close();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Hi ha hagut un error amb el chip");
    }
    finally {
        conn->Close();
    }

    return mascotaEncontrada;
}