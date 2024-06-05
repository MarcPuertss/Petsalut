#include "pch.h"
#include "TxModificarValoracio.h"
#include "PassarellaValoracio.h"

TxModificarValoracio^ TxModificarValoracio::prepara(int _numeroid_centre, int _numeroid_privat, String^ _propietari, int _valor)
{
    return gcnew TxModificarValoracio(_numeroid_centre, _numeroid_privat, _propietari, _valor);
}

TxModificarValoracio^ TxModificarValoracio::executa()
{
    PassarellaValoracio^ valoracioModificada = PassarellaValoracio::modificar(numeroid_centre, numeroid_privat, propietari, valor);
    numeroid_centre = valoracioModificada->NumeroidCentre;
    numeroid_privat = valoracioModificada->NumeroidPrivat;
    propietari = valoracioModificada->Propietari;
    valor = valoracioModificada->Valor;
    return this;
}

TxModificarValoracio::TxModificarValoracio(int _numeroid_centre, int _numeroid_privat, String^ _propietari, int _valor)
{
    numeroid_centre = _numeroid_centre;
    numeroid_privat = _numeroid_privat;
    propietari = _propietari;
    valor = _valor;
}
