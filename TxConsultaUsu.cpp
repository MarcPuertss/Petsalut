#include "pch.h"
#include "TxConsultaUsu.h"

TxConsultaUsu::Resultat TxConsultaUsu::obteResultat()
{
	return res;
}

PassarellaUsuari^ TxConsultaUsu::obteUsuari()
{
	return usu;
}

void TxConsultaUsu::crear()
{	
	res.nom = "";
	res.username = "";
	res.contrasenya = "";
	res.data = "";
	res.correu = "";
	res.descripcio = "";
	res.telefon = "";

}

void TxConsultaUsu::executar()
{

	Ordinador^ ord = Ordinador::getInstance();
	usu = ord->obteUsuari();

	if (usu->getTipus() == "propietari") {

		PassarellaPropietari^ prop = CercadoraPropietari::cercaPropietari(usu->getUsername());
		res.data = prop->getDataNaixement();

	}

	res.nom = usu->getNom();
	res.username = usu->getUsername();
	res.contrasenya = usu->getContrasenya(); 
	res.correu = usu->getCorreuElectronic();
	res.descripcio = usu->getDescripcio();
	res.telefon = usu->getTelefon();

}