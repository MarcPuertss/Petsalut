#pragma once
#include <iostream>
#include <string>
using namespace System::Collections::Generic;
using namespace System;
using namespace std;

ref class PassarellaVisites
{
private:
    int numero_id;
    int mascota;
    int centre;

public:
    // Constructores
    PassarellaVisites(int _numero_id, int _mascota, int _centre);

    // Métodos estáticos
    static PassarellaVisites^ crear(int _numero_id, int _mascota, int _centre);
    static PassarellaVisites^ eliminar(int numero_id);

    // Getters y setters
    property int Numero_ID {
        int get() { return numero_id; }
        void set(int value) { numero_id = value; }
    }

    property int Mascota {
        int get() { return mascota; }
        void set(int value) { mascota = value; }
    }

    property int Centre {
        int get() { return centre; }
        void set(int value) { centre = value; }
    }
};
