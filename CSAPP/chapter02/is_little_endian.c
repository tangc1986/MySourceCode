#include <stdio.h>

int is_little_endian()
{
    int ival = 0xABCD;
    unsigned char cval = (unsigned char)ival;
    if (cval == 0xCD)
        return 1;
    else
        return 0;
}

int main()
{
    printf("%d\n", is_little_endian());
}
