#include <stdio.h>
#include <assert.h>

unsigned rotate_right(unsigned x, int n)
{
    int w = sizeof(unsigned) * 8;
    int mask = (0x1<<n)-1;
    int end = x & mask;
    return (x >> n) + (end << w-n);
}

void test_01()
{
    assert(rotate_right(0x12345678, 4) == 0x81234567);
    assert(rotate_right(0x12345678, 20) == 0x45678123);
    assert(rotate_right(0x12345678, 0) == 0x12345678);


    printf("Success!\n");
}

int main()
{
    test_01();
}




