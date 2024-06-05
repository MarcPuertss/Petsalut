#include "pch.h"
#include "TxCrearParticipa.h"
#include "Ordinador.h"
#include "PassarellaParticipa.h"
#include "PassarellaUsuari.h"
#include "CercadoraPublic.h"
#include "PassarellaPublic.h"
void TxCrearParticipa::executar()
{
	Ordinador^ ord = Ordinador::getInstance();
	PassarellaUsuari^ pus = ord->obteUsuari();
	String^ username = pus->getUsername();
	int index = ord->Index;
	CercadoraPublic^ cpub = gcnew CercadoraPublic();
	PassarellaPublic^ ppub = cpub->cercaPublic(index);
	int numeroid = ppub->Numeroid;

	PassarellaParticipa^ ppart = gcnew PassarellaParticipa(numeroid, username);
	ppart->crear();
}
