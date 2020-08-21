#include "io.h"

int main()
{
    int x, y, z;
    x = readInteger();
    y = readInteger();
    z = x + y;

    writeAnswer(z);


    return(0);
}

