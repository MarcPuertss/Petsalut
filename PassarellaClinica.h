#pragma once
#include <iostream>
using namespace System;
using namespace System::Collections::Generic;
using namespace std;
ref class PassarellaClinica
{
private:
	String^ username;

public:
	PassarellaClinica::PassarellaClinica() : PassarellaClinica("") {}

	PassarellaClinica(String^ _username);

	PassarellaClinica^ crear();

	PassarellaClinica(const PassarellaClinica^ p);

	List<int>^ obtenirCentres();

	property String^ Username {
		String^ get() { return username; }
		void set(String^ value) { username = value; }
	}
};

