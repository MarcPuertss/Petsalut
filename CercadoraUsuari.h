
#pragma once

#include <iostream>
#include "PassarellaUsuari.h"

using namespace System;

ref class CercadoraUsuari
{

public:

	static PassarellaUsuari^ cercaUsuari(String^ usernameU);

};
