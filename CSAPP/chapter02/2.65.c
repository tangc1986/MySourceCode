#include <stdio.h>
#include <assert.h>
#include <limits.h>

int even_ones(unsigned x)
{
    unsigned step1 = (x>>16)^x;
    unsigned step2 = (step1>>8)^step1;
    unsigned step3 = (step2>>4)^step2;
    unsigned step4 = (step3>>2)^step3;
    unsigned step5 = (step4>>1)^step4;
    return (step5 & 0x1) != 1;
}

void test_01()
{
    assert(even_ones(0b1010) == 1);
    assert(even_ones(0b1011) == 0);
    assert(even_ones(0) == 1);
    assert(even_ones(0xFFFFFFFF) == 1);
    assert(even_ones(0b1101101101) == 0);
    assert(even_ones(0b1111101101101) == 1);

    printf("Success!\n");
}

int main()
{
    test_01();
}

