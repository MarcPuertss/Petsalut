#include "pch.h"
#include "TxEliminarValoracio.h"
#include "PassarellaValoracio.h"
using namespace System;

TxEliminaValoracio::TxEliminaValoracio() {
}

TxEliminaValoracio^ TxEliminaValoracio::crear()
{
    return gcnew TxEliminaValoracio();
}

void TxEliminaValoracio::ejecutar(int numeroid_centre, int numeroid_privat)
{
    PassarellaValoracio::eliminar(numeroid_centre, numeroid_privat);
}