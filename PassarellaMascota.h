#pragma once
#include <vector>
#include <iostream>
using namespace System;
using namespace std;

ref class PassarellaMascota
{
private:
    int chip;
    String^ nom;
    DateTime datanaixement;
    String^ descripcio;
    String^ propietari;
    String^ tipus;

public:
    // Constructor
    PassarellaMascota(int _chip, String^ _nom, DateTime _datanaixement, String^ _descripcio, String^ _propietari, String^ _tipus);
    static PassarellaMascota^ crear(int _chip, String^ _nom, DateTime _datanaixement, String^ _descripcio, String^ _propietari, String^ _tipus);
    static PassarellaMascota^ eliminar(int _chip);
    // Getters y setters
    property int Chip {
        int get() { return chip; }
        void set(int value) { chip = value; }
    }

    property String^ Nom {
        String^ get() { return nom; }
        void set(String^ value) { nom = value; }
    }

    property DateTime DataNaixament {
        DateTime get() { return datanaixement; }
        void set(DateTime value) { datanaixement = value; }
    }

    property String^ Descripcio {
        String^ get() { return descripcio; }
        void set(String^ value) { descripcio = value; }
    }

    property String^ Propietari {
        String^ get() { return propietari; }
        void set(String^ value) { propietari = value; }
    }

    property String^ Tipus {
        String^ get() { return tipus; }
        void set(String^ value) { tipus = value; }
    }

    virtual String^ ToString() override {
        // Aquí defines cómo quieres que se muestre cada mascota en la ComboBox
        return Nom + " (" + Chip.ToString() + ")";
    }

    vector<int> obtenerVisites();
};