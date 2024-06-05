#pragma once
#include <iostream>
using namespace System;
using namespace std;

ref class TxCrearValoracio
{
private:
    int numeroid_centre;
    int numeroid_privat;
    String^ propietari;
    int valor;
    TxCrearValoracio(int _numeroid_centre, int _numeroid_privat, String^ _propietari, int _valor);
public:
    // Constructor
    static TxCrearValoracio^ crear(int _numeroid_centre, int _numeroid_privat, String^ _propietari, int _valor);
    void ejecutar();
};
