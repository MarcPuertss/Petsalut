#pragma once
#include <iostream>
using namespace System;
using namespace std;
ref class TxEliminaCentre
{
private:
	int numero_ID;
	TxEliminaCentre();

public:
	static TxEliminaCentre^ crear();
	void ejecutar(int numero_ID);
};
