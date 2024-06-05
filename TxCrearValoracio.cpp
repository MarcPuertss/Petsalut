#include "pch.h"
#include "TxCrearValoracio.h"
#include <iostream>
#include "PassarellaValoracio.h"
using namespace System;
using namespace std;

// Implementación de la función para crear una nueva valoración
TxCrearValoracio^ TxCrearValoracio::crear(int _numeroid_centre, int _numeroid_privat, String^ _propietari, int _valor) {
    return gcnew TxCrearValoracio(_numeroid_centre, _numeroid_privat, _propietari, _valor);
}

void TxCrearValoracio::ejecutar()
{
    PassarellaValoracio::crear(numeroid_centre, numeroid_privat, propietari, valor);
}

// Constructor privado para evitar instanciación directa
TxCrearValoracio::TxCrearValoracio(int _numeroid_centre, int _numeroid_privat, String^ _propietari, int _valor) {
    numeroid_centre = _numeroid_centre;
    numeroid_privat = _numeroid_privat;
    propietari = _propietari;
    valor = _valor;
}
