//--------------------------------------------------------------------------------
// Swapping whole strings and string characters.
//
// Author: keejelo
//--------------------------------------------------------------------------------
/*

// One interesting way to use these two functions is to swap "endianess" of a large hexadecimal string

// Say we have this BIG-endian hex-string: 0xCAFEBABE
// which in LITTLE-endian becomes: 0xBEBAFECA

// To convert it, start by getting rid of "0x" somehow if the string contains it,
// then you can do this:

char myHexStr[] = "CAFEBABE"; // or any other hex value that is in a string type (if you have an integer you can try casting it into a string with sprintf)

// ** Create an output string that is big enough to hold our input string
char str1[255] = { 0 };

// ** Reverse all characters (make string mirrored)
ReverseString(myHexStr, str1);


// ** Create another output string
char str2[255] = { 0 };

// ** Now swap the "endianess"
SwapStringPair(str1, str2);

// ** Output string, should output: BEBAFECA
printf("%s", str2);

*/



//--------------------------------------------------------------------------------
// ** Swap characters one-by-one (first-to-last and so on) (mirrored)
//--------------------------------------------------------------------------------
bool ReverseString(char *strIn, char *strOut, const size_t bufferOut = 256)
{
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
