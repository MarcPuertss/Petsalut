#pragma once
#include "PassarellaParticipa.h"
ref class CercadoraParticipa
{
public:
	static PassarellaParticipa^ cercaParticipa(int numeroid, String^ usernameU);
	static int cuantosParticipa(int numeroid);
};

