//---------------------------------------------------------------------------------------------
// ** CC_Encrypt_Decrypt.cpp
//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------
// ** Include files
//---------------------------------------------------------------------------------------------
#include "CC_Encrypt_Decrypt.h"


//---------------------------------------------------------------------------------------------
// ** Caesar Cipher Encrypt 
//---------------------------------------------------------------------------------------------
std::string CC_Encrypt(std::string strIn, int key)
{
    std::string strOut = strIn;

    for (size_t i = 0; i < strIn.size(); i++)
    {
        strOut[i] += key;
    }
    return strOut;
};
//---------------------------------------------------------------------------------------------
// ** END: Caesar Cipher Encrypt 
//---------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------
// ** Caesar Cipher Decrypt
//---------------------------------------------------------------------------------------------
std::string CC_Decrypt(std::string strIn, int key)
{
    std::string strOut = strIn;

    for (size_t i = 0; i < strIn.size(); i++)
    {
        strOut[i] -= key;
    }
    return strOut;
};
//---------------------------------------------------------------------------------------------
// ** END: Caesar Cipher Decrypt
//---------------------------------------------------------------------------------------------
