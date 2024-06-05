
#include "pch.h"
#include "Ordinador.h"

void Ordinador::iniciaSessio(PassarellaUsuari^ c)
{
	ord->setUsername(c->getUsername());
	ord->setNom(c->getNom());
	ord->setContrasenya(c->getContrasenya());
	ord->setTipus(c->getTipus());
	ord->setTelefon(c->getTelefon());
	ord->setCorreuElectronic(c->getCorreuElectronic());
	ord->setDescripcio(c->getDescripcio());
}

void Ordinador::tancaSessio()
{
	ord->setUsername("");
	ord->setNom("");
	ord->setContrasenya("");
	ord->setTipus("");
	ord->setCorreuElectronic("");
	ord->setDescripcio("");
	ord->setTelefon("");

	delete instance;
	instance = nullptr;
}

void Ordinador::actualitza(String^ username, String^ nom, String^ passwd, String^ tipus, String^ correu, String^ descripcio, String^ telefon)
{
	ord->setUsername(username);
	ord->setNom(nom);
	ord->setContrasenya(passwd);
	ord->setTipus(tipus);
	ord->setCorreuElectronic(correu);
	ord->setDescripcio(descripcio);
	ord->setTelefon(telefon);
}

PassarellaUsuari^ Ordinador::obteUsuari()
{
	return ord;
}
