#pragma once

#include "pch.h"
#include <iostream>
#include "DBConnection.h"
#include "PassarellaUsuari.h"
#include "PassarellaPropietari.h"
#include "PassarellaClinica.h"

using namespace System;

ref class TxRegistraUsu
{

private:
	String^ username;
	String^ contrasenya;
	String^ nomComplert;
	String^ telefon;
	String^ tipus;
	String^ correuElectronic;
	String^ descripcio;
	String^ data;

public:

	void crear(String^ usernameS, String^ contrasenyaS, String^ nomComplertS, String^ telefonS, String^ tipusS, String^ correuElectronicS, String^ descripcioS, String^ dataS);
	void executar();

};