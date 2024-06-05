#pragma once
#include <iostream>
using namespace System;
using namespace std;

ref class TxEliminaValoracio
{
private:
    int numeroid_centre;
    int numeroid_privat;

    TxEliminaValoracio();

public:
    static TxEliminaValoracio^ crear();
    void ejecutar(int numeroid_centre, int numeroid_privat);
};
