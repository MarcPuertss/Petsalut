#pragma once
#include "PassarellaValoracio.h"

using namespace System;

ref class CercadoraValoracio
{
public:
    static PassarellaValoracio^ cercaValoracio(int numeroid_centre, int numeroid_privat);
    static int^ cercaValMitja(int idcentre);
};
 