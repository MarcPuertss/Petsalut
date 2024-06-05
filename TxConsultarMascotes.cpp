#include "pch.h"
#include "TxConsultarMascotes.h"


// Implementación del constructor
TxConsultarMascotes::TxConsultarMascotes(PassarellaPropietari^ _propietari) {
    propietari = _propietari;
}

TxConsultarMascotes^ TxConsultarMascotes::crear(PassarellaPropietari^ _propietari) {
    return gcnew TxConsultarMascotes(_propietari);
}

vector<int> TxConsultarMascotes::obteResultat()
{
    vector<int>mascotas = propietari->obtenerMascotas();
     return mascotas;

 
}
