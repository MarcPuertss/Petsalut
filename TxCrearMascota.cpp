#include "pch.h"
#include "TxCrearMascota.h"
#include <iostream>
#include "PassarellaMascota.h"
using namespace System;
using namespace std;
// Implementaci�n de la funci�n para crear una nueva mascota
TxCrearMascota^ TxCrearMascota::crear(String^ _name, DateTime _date, int _chip, String^ _type, String^ _propietari, String^ _description) {
    return gcnew TxCrearMascota(_name, _date, _chip, _type, _propietari, _description);
}

void TxCrearMascota::ejecutar()
{
    PassarellaMascota::crear(chip, name, date, description, propietari, type);


}

// Constructor privado para evitar instanciaci�n directa
TxCrearMascota::TxCrearMascota(String^ _name, DateTime _date, int _chip, String^ _type, String^ _propietari, String^ _description) {
    name = _name;
    date = _date;
    chip = _chip;
    type = _type;
    propietari = _propietari;
    description = _description;

}