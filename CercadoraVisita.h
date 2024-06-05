#pragma once
#include "PassarellaVisites.h"
using namespace System::Collections::Generic;
using namespace System;
using namespace std;
ref class CercadoraVisita
{
public:
	static PassarellaVisites^ cercaVisita(int numero_id);
	static List<PassarellaVisites^>^ cercaVisites(int numero_id);
};