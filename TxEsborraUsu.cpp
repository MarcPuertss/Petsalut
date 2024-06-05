#include "pch.h"
#include "TxEsborraUsu.h"

void TxEsborraUsu::crear(String^ contra)
{

    contraU = contra;

}

void TxEsborraUsu::executar()
{

    Ordinador^ ord = Ordinador::getInstance();
    PassarellaUsuari^ usu = ord->obteUsuari();

    if (contraU != usu->getContrasenya())
        throw gcnew Exception("La contrasenya no es correcta, l'usuari no s'ha esborrat");

    usu->esborra(contraU);

}
