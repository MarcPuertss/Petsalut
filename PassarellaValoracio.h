#pragma once
#include <iostream>
using namespace System;

ref class PassarellaValoracio
{
private:
    int numeroid_centre;
    int numeroid_privat;
    String^ propietari;
    int valor;

public:
    // Constructor
    PassarellaValoracio(int _numeroid_centre, int _numeroid_privat, String^ _propietari, int _valor);
    static PassarellaValoracio^ crear(int _numeroid_centre, int _numeroid_privat, String^ _propietari, int _valor);
    static PassarellaValoracio^ modificar(int _numeroid_centre, int _numeroid_privat, String^ _propietari, int _valor);
    static PassarellaValoracio^ eliminar(int _numeroid_centre, int _numeroid_privat);
    // Getters y setters
    property int NumeroidCentre {
        int get() { return numeroid_centre; }
        void set(int value) { numeroid_centre = value; }
    }

    property int NumeroidPrivat {
        int get() { return numeroid_privat; }
        void set(int value) { numeroid_privat = value; }
    }

    property String^ Propietari {
        String^ get() { return propietari; }
        void set(String^ value) { propietari = value; }
    }

    property int Valor {
        int get() { return valor; }
        void set(int value) { valor = value; }
    }

};