
#include "pch.h"
#include "TxIniciSessio.h"
#include "PasswordEncrypt.h"
void TxIniciSessio::crear(String^ sU, String^ cU)
{
	username = sU;
	contrasenya = cU;
}

void TxIniciSessio::executar()
{
	try {

		PassarellaUsuari^ usu = CercadoraUsuari::cercaUsuari(username);
		String^ cont = usu->getContrasenya();
		//encriptar contraseña que te dan
		contrasenya= PasswordEncrypt::Encrypt(contrasenya);

		if (cont != contrasenya)
			throw gcnew Exception("Hi ha hagut un error amb el nom d'usuari o la contrasenya");

		Ordinador^ ord = Ordinador::getInstance();
		ord->iniciaSessio(usu);

	}

	catch (Exception^ ex) {

		throw gcnew Exception("Hi ha hagut un error amb el nom d'usuari o la contrasenya");

	}

}
