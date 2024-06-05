#pragma once
#include <string>
#include <vector>
#include "PassarellaMascota.h"
using namespace System;
using namespace std;

ref class TxConsultarVisites
{
private:
    PassarellaMascota^ mascota;
    TxConsultarVisites(PassarellaMascota^ _mascota);

public:
    static TxConsultarVisites^ crear(PassarellaMascota^ _mascota);
    vector<int> obteResultat();
};
