#include <stdio.h>
#include <assert.h>
#include <limits.h>

int fun(int x)
{
    return (x^-1) == 0 || (x|0) == 0 || ((x>>24) & 0xFF) == 0xFF || (x&0xFF) == 0;
}

void test_01()
{
    assert(fun(-1) == 1);
    assert(fun(0) == 1);
    assert(fun(0xFF000000) == 1);
    assert(fun(0x123400) == 1);

    printf("Success!\n");
}

int main()
{
    test_01();
}


