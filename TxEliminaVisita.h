#pragma once
#include <iostream>
using namespace System;
using namespace std;
ref class TxEliminaVisita
{
private:
	int chip;
	TxEliminaVisita();

public:
	static TxEliminaVisita^ crear();
	void ejecutar(int chip);
};

