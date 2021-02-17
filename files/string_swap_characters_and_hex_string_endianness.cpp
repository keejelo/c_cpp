//--------------------------------------------------------------------------------
// Some string functions:
//
// 1. Remove all spaces in string
// 2. Swap characters one-by-one (first-to-last and so on) (mirrored)
// 3. Swap each character in a pair with eachother (converts "abcdef" into "badcfe")
// 4. Swap Endianness of HEX-string (combines the above functions to swap endianness)
// 5. Convert hex-string into a byte array
//
//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
// ** Remove all spaces in a string
//--------------------------------------------------------------------------------
void RemoveSpaces(char *strIn)
{
    // To keep track of non-space character count 
    int count = 0;

    // Traverse the given string. If current character 
    // is not space, then place it at index 'count++' 
    for (int i = 0; strIn[i]; i++)
    {
        if (strIn[i] != ' ')
        {
            strIn[count++] = strIn[i]; // here count is incremented 
        }
    }    

    strIn[count] = '\0';
};
//--------------------------------------------------------------------------------
// ** END: Remove all spaces in a string
//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
// ** Swap characters one-by-one (first-to-last and so on) (mirrored)
//--------------------------------------------------------------------------------
bool ReverseString(char *strIn, char *strOut, const size_t bufferOut = 256)
{
    size_t len = strlen(strIn);

    if (bufferOut < len)
    {
        printf("Error, buffer output size must be greater or equal to string input length.\n");
        return false;
    }
    
    for (size_t i = 0; i < len; i++)
    {
        strOut[(len - 1) - i] = strIn[i];

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
// ** Swap each character in a pair with eachother (converts "ab cd ef" into "ba dc fe")
//--------------------------------------------------------------------------------
bool SwapStringPair(char *strIn, char *strOut, const size_t bufferOut = 256)
{
    size_t len = strlen(strIn);

    if (bufferOut < len)
    {
        printf("Error, buffer output size must be greater or equal to string input length.\n");
        return false;
    }
    
    if (len % 2 != 0)
    {
        printf("Error, not possible to swap string pairs as the string length is odd, it must be even.\n");
        return false;
    }

    for (size_t i = 0; i < len; i += 2)
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
// ** Swap Endianness of hex-string
//--------------------------------------------------------------------------------
bool SwapEndianHexString(char *strIn, char *strOut)
{
    char strTemp[255] = { 0 };
    
    // ** Remove all spaces
    RemoveSpaces(strIn);
    
    // ** If string starts with hex-prefix "0x" or "0X" we remove it
    if (strIn[0] == '0' && (strIn[1] == 'x' || strIn[1] == 'X'))
    {
        strIn += 2;
    }

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
// ** END: Swap Endianness of hex-string
//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
// ** Convert hex-string into a byte array
//--------------------------------------------------------------------------------
void HexStringToByteArray(char *strIn, unsigned int *byteArr)
{
    // ** Remove all spaces
    RemoveSpaces(strIn);
    
    // ** If string starts with hex-prefix "0x" or "0X" we remove it
    if (strIn[0] == '0' && (strIn[1] == 'x' || strIn[1] == 'X'))
    {
        strIn += 2;
    }

    for (size_t i = 0; i < (strlen(strIn) / 2); i++)
    {
        sscanf_s(strIn + 2 * i, "%02X", &byteArr[i]);
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
//
// Example:
// Say we have this BIG-endian hex-string: 0xCAFEBABE 
// which in LITTLE-endian becomes: 0xBEBAFECA
// And we want to convert 0xBEBAFECA into a byte array: '0xBE','0xBA','0xFE','0xCA'
//
// Then this is how we can do it:

#include <stdio.h>


int main()
{
    // Enter a hex value that is in a string type (if you have an integer you can try casting it into a string with sprintf)
    // The "0x" will be removed if the string contains it, since it will fail our operation
    char myHexStr[] = "0xCAFEBABE";

    // Create an output string that is big enough to hold our input string
    char myOutHexStr[255] = { 0 };

    // Now swap endianness
    SwapEndianHexString(myHexStr, myOutHexStr);

    // Output should now be: BEBAFECA
    printf("EndianSwap:%s\n", myOutHexStr);


    // If you then want to convert that string into a byte array, do this:

    unsigned int byteArr[255];

    HexStringToByteArray(myOutHexStr, byteArr);

    // Print out bytearray values one-by-one
    for (size_t i = 0; i < (strlen(myOutHexStr) / 2); i++)
    {
        printf("Bytearray %d: 0x%02X\n", i, byteArr[i]);
    }

    return 0;
};

*/
