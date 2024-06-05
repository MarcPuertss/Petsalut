#include "pch.h"
#include "TxEsborraParticipa.h"
#include "Ordinador.h"
#include "PassarellaParticipa.h"
#include "PassarellaUsuari.h"
#include "CercadoraPublic.h"
#include "PassarellaPublic.h"

void TxEsborraParticipa::executar()
{
	Ordinador^ ord = Ordinador::getInstance();
	PassarellaUsuari^ pus = ord->obteUsuari();
	String^ username = pus->getUsername();
	int index = ord->Index;
	CercadoraPublic^ cpub = gcnew CercadoraPublic();
	PassarellaPublic^ ppub = cpub->cercaPublic(index);
	int numero_id = ppub->Numeroid;
	PassarellaParticipa^ ppart = gcnew PassarellaParticipa(numero_id, username);
	ppart->eliminar();
	
}
