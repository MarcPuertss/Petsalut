#pragma once

#include "pch.h"
#include <iostream>
#include "CercadoraUsuari.h"
#include "Ordinador.h"

using namespace System;

ref class TxIniciSessio
{

private:

	String^ username;
	String^ contrasenya;

public:

	void crear(String^ sU, String^ cU);
	void executar();

};
