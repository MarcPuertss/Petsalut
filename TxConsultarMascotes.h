#pragma once
#include <string>
#include "PassarellaPropietari.h"
using namespace System;
using namespace std;

ref class TxConsultarMascotes
{
private:
    PassarellaPropietari^ propietari;
    // Constructor
    TxConsultarMascotes(PassarellaPropietari^ _propietari);

public:
  
    
    // Función para crear una instancia de TxConsultarMascotes
    static TxConsultarMascotes^ crear(PassarellaPropietari^ _propietari);
    vector<int> obteResultat();
 

};
