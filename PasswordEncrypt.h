#pragma once
ref class PasswordEncrypt
{
	public:
	PasswordEncrypt();
	static System::String^ Encrypt(System::String^ password);
	static System::String^ Decrypt(System::String^ password);



};

