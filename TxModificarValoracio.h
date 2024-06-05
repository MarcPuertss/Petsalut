#pragma once
#include <iostream>
using namespace System;
using namespace std;

ref class TxModificarValoracio
{
private:
    int numeroid_centre;
    int numeroid_privat;
    String^ propietari;
    int valor;
    TxModificarValoracio(int _numeroid_centre, int _numeroid_privat, String^ _propietari, int _valor);

public:
    static TxModificarValoracio^ prepara(int _numeroid_centre, int _numeroid_privat, String^ _propietari, int _valor);
    TxModificarValoracio^ executa();

};
