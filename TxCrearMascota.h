#pragma once
#include <iostream>
using namespace System;
using namespace std;
ref class TxCrearMascota
{
private:
    String^ name;
    DateTime date;
    int chip;
    String^ type;
    String^ propietari;
    String^ description;
    TxCrearMascota(String^ _name, DateTime _date, int _chip, String^ _type, String^ _propietari, String^ _description);
public:
    // Constructor
    static TxCrearMascota^ crear(String^ _name, DateTime _date, int _chip, String^ _type, String^ _propietari, String^ _description);
    void ejecutar();

};



