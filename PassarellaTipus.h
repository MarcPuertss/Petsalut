#pragma once
#include <iostream>
using namespace System;
using namespace std;
ref class PassarellaTipus
{	
private:
	String^ nom;
public:
	PassarellaTipus(String^ _nom);

	property String^ Nom {
		String^ get() { return nom; }
		void set(String^ value) { nom = value; }
	}
};

