#include "pch.h"
#include "TxEliminaCentre.h"
#include "PassarellaCentre.h"
using namespace System;

TxEliminaCentre::TxEliminaCentre() {
}

TxEliminaCentre^ TxEliminaCentre::crear()
{
    return gcnew TxEliminaCentre();
}

void TxEliminaCentre::ejecutar(int numero_ID)
{
    ;
    PassarellaCentre::eliminar(numero_ID);
}