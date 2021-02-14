//--------------------------------------------------------------------------------
// Some string functions:
//
// 1. Swap characters one-by-one (first-to-last and so on) (mirrored)
// 2. Swap each character in a pair with eachother (converts "abcdef" into "badcfe")
// 3. Swap Endianness of HEX-string (combines the above functions to swap endianness)
// 4. Convert hex-string into a byte array
//
// Author: keejelo
//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
// ** Swap characters one-by-one (first-to-last and so on) (mirrored)
//--------------------------------------------------------------------------------
bool ReverseString(char *strIn, char *strOut, const size_t bufferOut = 256, bool bRemoveHexPrefix = true)
{    
    // ** If string contains hex-prefix "0x" we remove it   
    if (bRemoveHexPrefix && strIn[0] == '0' && (strIn[1] == 'x' || strIn[1] == 'X'))
    {
        strIn = strIn + 2;
    }
    
    size_t strInLen = strlen(strIn);
    if (bufferOut < strInLen)
    {
        printf("Error, buffer output size must be greater or equal to string input length.\n");
        return false;
    }
    
    for (size_t i = 0; i < strInLen; i++)
    {
        strOut[(strInLen - 1) - i] = strIn[i];

        if (strIn[i] == '\0')
        {
            break; // we exit when string input ends
        }
    }

    return true;
};
//--------------------------------------------------------------------------------
// ** END: Swap characters one-by-one
//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
// ** Swap each character in a pair with eachother (converts "abcdef" into "badcfe")
//--------------------------------------------------------------------------------
bool SwapStringPair(char *strIn, char *strOut, const size_t bufferOut = 256)
{
    size_t strInLen = strlen(strIn);

    if (bufferOut < strInLen)
    {
        printf("Error, buffer output size must be greater or equal to string input length.\n");
        return false;
    }
    
    if (strInLen % 2 != 0)
    {
        printf("Error, not possible to swap string pairs as the string length is odd, it must be even.\n");
        return false;
    }

    for (size_t i = 0; i < strInLen; i += 2)
    {
        strOut[i] = strIn[i + 1];
        strOut[i + 1] = strIn[i];
    }

    return true;
};
//--------------------------------------------------------------------------------
// ** END: Swap each character in a pair
//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
// ** Swap Endianness of HEX-string
//--------------------------------------------------------------------------------
bool SwapEndianHexString(char *strIn, char *strOut)
{
    char strTemp[256] = { 0 };

    if (ReverseString(strIn, strTemp))
    {
        size_t len = strlen(strIn);
        
        // ** If odd number, we even it out by adding a zero to the first digit making it a "byte" value format
        if (len % 2 != 0)
        {
            strcat_s(strTemp, (len * 2) + 2, "0");
        }

        if (SwapStringPair(strTemp, strOut))
        {
            return true;
        }
    }

    return false;
};
//--------------------------------------------------------------------------------
// ** END: Swap Endianness of HEX-string
//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
// ** Convert hex-string into a byte array
//--------------------------------------------------------------------------------
void HexStringToByteArray(char *hexStr, unsigned int *byteArr)
{
    for (size_t i = 0; i < (strlen(hexStr) / 2); i++)
    {
        sscanf_s(hexStr + 2 * i, "%02X", &byteArr[i]);
        //printf("bytearray %d: %02X\n", i, byteArr[i]);
    }
};
//--------------------------------------------------------------------------------
// ** END: Convert hex-string into a byte array
//--------------------------------------------------------------------------------




/*
// EXAMPLE USAGE
//
// One interesting way to use these functions is to swap "endianness" of a large hexadecimal string,
// and then convert that string into a byte array for further processing.
// This should work for any hex-string length, no matter how long since it deals with a string and not a fixed byte value.
// So searching for a large hex pattern in a file, memory, buffer etc. should be no problem.
//
// Example:
// Say we have this BIG-endian hex-string: 0xCAFEBABE 
// which in LITTLE-endian becomes: 0xBEBAFECA
//
// This is how we can do things:


#include <stdio.h>

int main()
{
    char myHexStrZeroX[] = "0xCAFEBABE"; // or any other hex value that is in a string type (if you have an integer you can try casting it into a string with sprintf)
    
    // Start by getting rid of "0x"  (if the string contains it)
    char *myHexStr = myHexStrZeroX + 2;

    // .. else if you do not have "0x" at string start, just do:
    // char myHexStr[] = "CAFEBABE";

    // Create an output string that is big enough to hold our input string
    char outstr[9] = { 0 };

    // Now swap endianness
    SwapEndianHexString(myHexStr, outstr);

    // Output should now be: BEBAFECA
    printf("EndianSwap:%s\n", outstr);


    // If you then want to convert the string into a byte array you can do this:

    unsigned int byteArr[255];

    HexStringToByteArray(myHexStr, byteArr);

    // Print out bytearray values one-by-one
    for (size_t i = 0; i < (strlen(myHexStr) / 2); i++)
    {
        printf("Bytearray %d: %02X\n", i, byteArr[i]);
    }

    return 0;
};

*/

