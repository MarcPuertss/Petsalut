#pragma once
#include <iostream>
using namespace System;
using namespace std;
ref class TxCrearAten
{
private:
    int^ idcentre;
    String^ tipus;
    TxCrearAten(String^ _tipus, int^ _idcentre);
public:
    // Constructor
    static TxCrearAten^ crear(String^ _tipus, int^ _idcentre);
    void ejecutar();

};
