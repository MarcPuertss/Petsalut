#pragma once

#include "pch.h"
#include <iostream>
#include "Ordinador.h"
#include "PassarellaPropietari.h"
#include "CercadoraPropietari.h"

ref class TxConsultaUsu
{

public:

	value struct Resultat {

		String^ username;
		String^ nom;
		String^ contrasenya;
		String^ correu;
		String^ telefon;
		String^ data;
		String^ descripcio;

	};

	Resultat obteResultat();
	PassarellaUsuari^ obteUsuari();
	void crear();
	void executar();

private:

	Resultat res;
	PassarellaUsuari^ usu;

};