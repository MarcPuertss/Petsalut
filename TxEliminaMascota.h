#pragma once
#include <iostream>
using namespace System;
using namespace std;
ref class TxEliminaMascota
{
private:
	int chip;
	TxEliminaMascota();

public:
	static TxEliminaMascota^ crear();
	void ejecutar(int chip);
};

