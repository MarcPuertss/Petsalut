#pragma once
#include <string>
#include <vector>
#include "PassarellaClinica.h"
using namespace System::Collections::Generic;
using namespace System;
using namespace std;

ref class TxConsultarCentres
{
private:
    PassarellaClinica^ clinica;
    // Constructor
    TxConsultarCentres(PassarellaClinica^ _clinica);

public:


    // Funci�n para crear una instancia de TxConsultarCentres
    static TxConsultarCentres^ crear(PassarellaClinica^ _clinica);
    List<int>^ ObtenirResultat();


};