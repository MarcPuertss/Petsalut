#pragma once
#include <iostream>
#include "PassarellaClinica.h"
using namespace System;

ref class CercadoraClinica
{
public:
	static PassarellaClinica^ cercaClinica(String^ usernameU);
};




