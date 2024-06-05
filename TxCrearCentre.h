#pragma once
#include <iostream>
using namespace System;
using namespace std;
ref class TxCrearCentre
{
private:
    String^ nom;
    int numero_ID;
    String^ telefon;
    String^ clinica;
    String^ ubicacio;
    TxCrearCentre(String^ _nom, String^ _telefon, String^ _clinica, String^ _ubicacio);
public:
    // Constructor
    static TxCrearCentre^ crear(String^ _nom, String^ _telefon, String^ _clinica, String^ _ubicacio);

    TxCrearCentre^ ejecutar();


    // Getters and Setters only on .h
    property int Numero_ID{
        int get() { return numero_ID; }
    }
};