#include "pch.h"
#include "TxTancaSessio.h"

void TxTancaSessio::crear() {}

void TxTancaSessio::executar()
{
	Ordinador^ ord = Ordinador::getInstance();    
	ord->tancaSessio();

}
