#pragma once
#include <iostream>
#include <string>
using namespace System::Collections::Generic;
using namespace System;
using namespace std;

ref class PassarellaCentre
{
private:
    int numero_ID;
    String^ nom;
    String^ telefon;
    String^ clinica;
    String^ ubicacio;

public:
     // Constructor
    PassarellaCentre();
    PassarellaCentre(String^ _nom, String^ _telefon, String^ _clinica, String^ _ubicacio);
    PassarellaCentre(int _numero_ID, String^ _nom, String^ _telefon, String^ _clinica, String^ _ubicacio);
    static PassarellaCentre^ crear(String^ _nom, String^ _telefon, String^ _clinica, String^ _ubicacio);
    static PassarellaCentre^ modificar(int numero_ID, String^ _nom, String^ _telefon, String^ _clinica, String^ _ubicacio);
    static PassarellaCentre^ eliminar(int _numero_ID);

    // Getters y setters
    property int Numero_ID {
        int get() { return numero_ID; }
        void set(int value) { numero_ID = value; }
    }

    property String^ Nom {
        String^ get() { return nom; }
        void set(String^ value) { nom = value; }
    }

    property String^ Telefon {
        String^ get() { return telefon; }
        void set(String^ value) { telefon = value; }
    }

    property String^ Clinica {
        String^ get() { return clinica; }
        void set(String^ value) { clinica = value; }
    }
    property String^ Ubicacio {
        String^ get() { return ubicacio; }
        void set(String^ value) { ubicacio = value; }
    }

    virtual String^ ToString() override {
        // Aquí defines cómo quieres que se muestre cada centro en la ComboBox
        return Nom + " (" + Ubicacio + ")";
    }

};