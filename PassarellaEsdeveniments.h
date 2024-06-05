#pragma once

#include "pch.h"
#include <iostream>
#include "DBConnection.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
ref class PassarellaEsdeveniments
{
private:
	int numeroid;
	String^ nom;
	DateTime data;
	String^ hora;
	String^ propietari;
    String^ tipus;

public:

	PassarellaEsdeveniments(int _numeroid, String^ _nom, DateTime _data, String^ _hora, String^ _propietari, String^ _tipus);

	void crear();

	void eliminar();

    property int Numeroid {
        int get() { return numeroid; }
        void set(int value) { numeroid = value; }
    }

    property String^ Nom {
        String^ get() { return nom; }
        void set(String^ value) { nom = value; }
    }

    property DateTime Data {
        DateTime get() { return data; }
        void set(DateTime value) { data = value; }
    }

    property String^ Hora {
        String^ get() { return hora; }
        void set(String^ value) { hora = value; }
    }

    property String^ Propietari {
        String^ get() { return propietari; }
        void set(String^ value) { propietari = value; }
    }
    property String^ Tipus {
        String^ get() { return tipus; }
        void set(String^ value) { tipus = value; }
    }
};
