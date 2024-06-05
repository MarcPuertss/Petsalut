#include "pch.h"
#include "TxConsultarCentres.h"

using namespace System::Collections::Generic;
using namespace System;
using namespace std;
// Implementación del constructor
TxConsultarCentres::TxConsultarCentres(PassarellaClinica^ _clinica) {
    clinica = _clinica;
}

TxConsultarCentres^ TxConsultarCentres::crear(PassarellaClinica^ _clinica) {
    return gcnew TxConsultarCentres(_clinica);
}

List<int>^ TxConsultarCentres::ObtenirResultat()
{
    List<int>^ centres = clinica->obtenirCentres();
    return centres;
}