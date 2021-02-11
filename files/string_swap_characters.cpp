//--------------------------------------------------------------------------------
// ** Swap characters one-by-one (first-to-last and so on) (mirrored)
//--------------------------------------------------------------------------------
bool ReverseString(char *strIn, char *strOut, const size_t bufferOut = 255)
{
    size_t strInLen = strlen(strIn);

    if (bufferOut < strInLen)
    {
        printf("Error, buffer output size must be greater or equal to string input length.\n");
        return false;
    }
    
    // ** Swap characters one-by-one (first-to-last and so on) (mirrored)
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
// ** Swap each pair character
//--------------------------------------------------------------------------------
bool SwapStringPair(char *strIn, char *strOut, const size_t bufferOut = 255)
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

    // ** Swap each character pair to get set the correct "byte" value
    for (size_t i = 0; i < strInLen; i += 2)
    {
        strOut[i] = strIn[i + 1];
        strOut[i + 1] = strIn[i];
    }

    return true;
};
//--------------------------------------------------------------------------------
// ** END: Swap each pair character
//--------------------------------------------------------------------------------