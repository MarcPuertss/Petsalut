#include "pch.h"
#include "TxConsultarVisites.h"
#include "DBConnection.h"

using namespace MySql::Data::MySqlClient;
using namespace System::Collections::Generic;

TxConsultarVisites::TxConsultarVisites(PassarellaMascota^ _mascota) {
    mascota = _mascota;
}


TxConsultarVisites^ TxConsultarVisites::crear(PassarellaMascota^ _mascota){
    return gcnew TxConsultarVisites(_mascota);
}

vector<int> TxConsultarVisites::obteResultat() {
    vector<int> visites = mascota->obtenerVisites();
    return visites;
}
