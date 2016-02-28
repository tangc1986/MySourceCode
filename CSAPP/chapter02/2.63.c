#include <stdio.h>
#include <assert.h>
#include <limits.h>

int sra(int x, int k)
{
    int xsrl = (unsigned) x >> k;
    return xsrl | (((unsigned)-1) << (8*sizeof(int) - k));
}

unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int) x >> k;
    return xsra & ~(((unsigned)-1) << (8*sizeof(int) - k));
}

int main()
{
    printf("0x%08X\n", sra(0x80000000, 4));
    printf("0x%08X\n", srl(0x80000000, 4));
}




