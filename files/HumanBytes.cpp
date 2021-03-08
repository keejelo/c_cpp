/*
#include <string>
*/

//--------------------------------------------------------------------------------
// ** Make byte size human readable
//--------------------------------------------------------------------------------
std::string HumanBytes(unsigned int bytes)
{
    const char *suf[7];
    suf[0] = "B";
    suf[1] = "KB";
    suf[2] = "MB";
    suf[3] = "GB";
    suf[4] = "TB";
    suf[5] = "PB";
    suf[6] = "EB";

    unsigned int s = 0;
    double count = bytes;

    while (count >= 1000 && s < 7)
    {
        s++;
        count /= 1000;
    }

    char buf[16] = { 0 };

    if (count - floor(count) == 0.0)
    {
        sprintf_s(buf, sizeof(buf), "%d %s", (int)count, suf[s]);
    }
    else
    {
        sprintf_s(buf, sizeof(buf), "%.1f %s", count, suf[s]);
    }

    return buf;
};
//--------------------------------------------------------------------------------
// ** END: Make byte size human readable
//--------------------------------------------------------------------------------
