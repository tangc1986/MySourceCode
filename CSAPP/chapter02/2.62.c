#include <stdio.h>
#include <assert.h>
#include <limits.h>

int int_shifts_are_logical()
{
    int w = sizeof(int) << 3;
    int val = -1;
    return (val >> (w-1)) == 0x1;
}

void test_01()
{
    assert(int_shifts_are_logical() == 0);

    printf("Success!\n");
}

int main()
{
    test_01();
}



