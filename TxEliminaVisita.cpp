#include "pch.h"
#include "TxEliminaVisita.h"
#include "PassarellaVisites.h"
using namespace System;
TxEliminaVisita::TxEliminaVisita() {
}

TxEliminaVisita^ TxEliminaVisita::crear()
{
    return gcnew TxEliminaVisita();
}

void TxEliminaVisita::ejecutar(int chip)
{
    ;
    PassarellaVisites::eliminar(chip);
}
