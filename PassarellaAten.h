#pragma once
#include <iostream>
using namespace System;
using namespace std;
ref class PassarellaAten
{
private:
	String^ tipus;
	int^ idcentre;

public:
	PassarellaAten(String^ _tipus, int^ _idcentre);
	static PassarellaAten^ crear(String^ _tipus, int^ _idcentre);

	property String^ Tipus {
		String^ get() { return tipus; }
		void set(String^ value) { tipus = value; }
	}

	property int^ Idcentre {
		int^ get() { return idcentre; }
		void set(int^ value) { idcentre = value; }
	}
};
