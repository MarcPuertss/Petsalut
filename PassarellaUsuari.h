#pragma once

#include "pch.h"
#include <iostream>
#include "DBConnection.h"

using namespace System;

ref class PassarellaUsuari {

private:
	String^ username;
	String^ nom;
	String^ contrasenya;
	String^ correu;
	String^ telefon;
	String^ tipus;
	String^ descripcio;

public:

	PassarellaUsuari();

	PassarellaUsuari(String^ _username, String^ _nom, String^ _contrasenya, String^ _correu, String^ _telefon, String^ _tipus, String^ _descripcio);

	PassarellaUsuari(const PassarellaUsuari^ u);

	void crear();

	void esborra(String^ contrasenyaU);

	String^ getNom();
	String^ getUsername();
	String^ getContrasenya();
	String^ getTipus();
	String^ getCorreuElectronic();
	String^ getDescripcio();
	String^ getTelefon();

	void setNom(String^ nuevoNom);
	void setUsername(String^ nuevoUsername);
	void setContrasenya(String^ nuevaContrasenya);
	void setTipus(String^ nouTipus);
	void setCorreuElectronic(String^ nuevoCorreuElectronic);
	void setDescripcio(String^ nuevaDescripcion);
	void setTelefon(String^ nuevoTelefono);

};
