#pragma once
#include <iostream>
#include "PassarellaPublic.h"
using namespace System;
ref class CercadoraPublic
{
public:
	static PassarellaPublic^ cercaPublic(int index);
	static int maxIndex();
};

