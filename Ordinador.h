#pragma once
#include <iostream>
#include "PassarellaUsuari.h"
#include "DBConnection.h"

public ref class Ordinador
{
public:

	static Ordinador^ getInstance() {

		if (instance == nullptr)
			instance = gcnew Ordinador();

		return instance;

	}

	void iniciaSessio(PassarellaUsuari^ c);

	void tancaSessio();

	void actualitza(String^ username, String^ nom, String^ passwd, String^ tipus, String^ correu, String^ descripció, String^ telefon);

	PassarellaUsuari^ obteUsuari();
	property int Index {
		int get() { return index; }
		void set(int value) { index = value; }
	}


private:

	static Ordinador^ instance;
	PassarellaUsuari^ ord;
	int index=1;

	
	Ordinador::Ordinador()
	{
		ord = gcnew PassarellaUsuari();
	}

};