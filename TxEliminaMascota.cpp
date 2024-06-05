#include "pch.h"
#include "TxEliminaMascota.h"
#include "PassarellaMascota.h"
using namespace System;
TxEliminaMascota::TxEliminaMascota() {
}

TxEliminaMascota^ TxEliminaMascota::crear()
{
    return gcnew TxEliminaMascota();
}

void TxEliminaMascota::ejecutar(int chip)
{
  PassarellaMascota::eliminar(chip);
}
