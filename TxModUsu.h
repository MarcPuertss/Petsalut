#pragma once
#include "pch.h"
#include <iostream>
#include "DBConnection.h"
#include "PassarellaUsuari.h"

ref class TxModUsu
{

private:

	String^ _username;
	String^ _contrasenya;
	String^ _nomComplert;
	String^ _telefon;
	String^ _data;
	String^ _correuElectronic;
	String^ _descripcio;
	String^ _tipus;

public:

	void crear(String^ usernameS, String^ contrasenyaS, String^ nomComplertS, String^ telefonS, String^ dataS, String^ correuElectronicS, String^ descripcioS, String^ tipusS);
	void executar();

};

