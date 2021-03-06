//---------------------------------------------------------------------------------------------
// ** DEC_X_HEX_Convert.cpp
//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------
// ** Include files
//---------------------------------------------------------------------------------------------
#include "DEC_X_HEX_Convert.h"
#include <string>


//---------------------------------------------------------------------------------------------
// ** Decimal to HEX
//---------------------------------------------------------------------------------------------
std::string dec2hex(int num)
{
    char hex[10];
    sprintf_s(hex, "%x", num);
    return hex;
};
//---------------------------------------------------------------------------------------------
// ** END: Decimal to HEX
//---------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------
// ** HEX to Decimal
//---------------------------------------------------------------------------------------------
int hex2dec(const char *hex)
{
    int n = 0;
    if (sscanf_s(hex, "%x", &n) == 1)
    {
        return n;
    }
    else
    {
        puts("Error converting from hex to decimal");
    }
    return 0;
};
//---------------------------------------------------------------------------------------------
// ** END: HEX to Decimal
//---------------------------------------------------------------------------------------------



/*
// EXAMPLE:

#include <stdio.h>
#include "DEC_X_HEX_Convert.h"

int main()
{
    int num = 255;

    std::string str = dec2hex(num);
    printf("Decimal: %d converted to Hex = %s\n\n", num, str.c_str());

    num = hex2dec(str.c_str());
    printf("Hex: %s converted to Decimal = %d\n", str.c_str(), num);

    return 0;
}
*/


