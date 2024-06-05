#include "pch.h"
#include "TxCrearAten.h"
#include <iostream>
#include "PassarellaAten.h"
using namespace System;
using namespace std;
// Implementaci?n de la funci?n para crear una nueva mascota
TxCrearAten^ TxCrearAten::crear(String^ _tipus, int^ _idcentre) {
    return gcnew TxCrearAten(_tipus, _idcentre);
}

void TxCrearAten::ejecutar()
{
    PassarellaAten::crear(tipus, idcentre);
}

// Constructor privado para evitar instanciaci?n directa
TxCrearAten::TxCrearAten(String^ _tipus, int^ _idcentre) {
    tipus = _tipus;
    idcentre = _idcentre;
}

