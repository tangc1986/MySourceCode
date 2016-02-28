#include <stdio.h>

int fun(int x, int y)
{
    return (x & 0xFF) + (y & ~0xFF);
}

void test_01()
{
    printf("0x%X", fun(0x89ABCDEF, 0x76543210));
}

int main()
{
    test_01();
}



