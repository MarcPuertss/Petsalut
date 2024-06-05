#include "pch.h"
#include "PasswordEncrypt.h"
#include <cstddef>
using namespace std;

using namespace System;
using namespace System::Security::Cryptography;
using namespace System::Text;

PasswordEncrypt::PasswordEncrypt()
{

}

System::String^ PasswordEncrypt::Encrypt(System::String^ password)
{
    // Genera una sal aleatoria
    String^ salt = "Randomente";

    array<Byte>^ saltBytes = Encoding::UTF8->GetBytes(salt);

    Rfc2898DeriveBytes^ key = gcnew Rfc2898DeriveBytes(password, saltBytes);

    array<Byte>^ keyBytes = key->GetBytes(32);
    array<Byte>^ ivBytes = key->GetBytes(16); // Genera un IV de 16 bytes

    // Utiliza la clave para encriptar el texto
    RijndaelManaged^ rijndael = gcnew RijndaelManaged();
    rijndael->Key = keyBytes;
    rijndael->IV = ivBytes; // Usa el IV de 16 bytes

    ICryptoTransform^ encryptor = rijndael->CreateEncryptor();
    array<Byte>^ textBytes = Encoding::UTF8->GetBytes(password);

    // Cifra el texto
    array<Byte>^ encryptedBytes = encryptor->TransformFinalBlock(textBytes, 0, textBytes->Length);

    // Convierte el texto cifrado a una cadena
    return Convert::ToBase64String(encryptedBytes);
}

System::String^ PasswordEncrypt::Decrypt(System::String^ encryptedPassword)
{
    // Genera una sal aleatoria
    String^ salt = "Randomente";

    array<Byte>^ saltBytes = Encoding::UTF8->GetBytes(salt);

    Rfc2898DeriveBytes^ key = gcnew Rfc2898DeriveBytes(encryptedPassword, saltBytes);

    array<Byte>^ keyBytes = key->GetBytes(32);
    array<Byte>^ ivBytes = key->GetBytes(16); // Genera un IV de 16 bytes

    // Utiliza la clave para desencriptar el texto
    RijndaelManaged^ rijndael = gcnew RijndaelManaged();
    rijndael->Key = keyBytes;
    rijndael->IV = ivBytes; // Usa el IV de 16 bytes

    ICryptoTransform^ decryptor = rijndael->CreateDecryptor();
    array<Byte>^ encryptedBytes = Convert::FromBase64String(encryptedPassword);

    // Desencripta el texto
    array<Byte>^ decryptedBytes = decryptor->TransformFinalBlock(encryptedBytes, 0, encryptedBytes->Length);

    // Convierte el texto desencriptado a una cadena
    return Encoding::UTF8->GetString(decryptedBytes);
}