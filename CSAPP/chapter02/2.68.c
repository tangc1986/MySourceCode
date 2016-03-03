#include <stdio.h>
#include <assert.h>

int lower_bits(int n)
{
    int x = (0x1<<(n-1)) - 1;
    x = x + (0x1<<(n-1));
    return x;
}

void test_01()
{
    assert(lower_bits(6) == 0x3F);
    assert(lower_bits(17) == 0x1FFFF);
    assert(lower_bits(32) == 0xFFFFFFFF);
    assert(lower_bits(1) == 0x1);

    printf("Success!\n");
}

int main()
{
    test_01();
}



