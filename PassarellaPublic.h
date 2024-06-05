#pragma once

#include "pch.h"
#include <iostream>
#include "DBConnection.h"
using namespace System;

ref class PassarellaPublic {
private:

	String^ tipus;
	int numeroid;
	String^ descripcio;
	String^ ubicacio;


public:

	PassarellaPublic();

	PassarellaPublic(String^ _tipus, int _numeroid,String^ _descripcio, String^ _ubicacio);

	PassarellaPublic(const PassarellaPublic^ p);

	void crear();

	property int Numeroid {
		int get() { return numeroid; }
		void set(int value) { numeroid = value; }
	}

	property String^ Tipus {
		String^ get() { return tipus; }
		void set(String^ value) { tipus = value; }
	}
	property String^ Descripcio {
		String^ get() { return descripcio; }
		void set(String^ value) { descripcio = value; }
	}
	property String^ Ubicacio {
		String^ get() { return ubicacio; }
		void set(String^ value) { tipus = ubicacio; }
	}
};

