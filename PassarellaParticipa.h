#pragma once
#include "PassarellaPublic.h"
using namespace System;

ref class PassarellaParticipa
{
private:
    int numeroid;
    String^ username;
public:
    PassarellaParticipa();
    PassarellaParticipa(int _numeroid, String^ _username);
    PassarellaParticipa(const PassarellaParticipa^ p);
    void crear();
    void eliminar();
    property int Numeroid {
        int get() { return numeroid; }
        void set(int value) { numeroid = value; }
    }
    property String^ Username {
        String^ get() { return username; }
        void set(String^ value) { username = value; }
    }
};
