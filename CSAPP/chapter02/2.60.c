#include <stdio.h>
#include <assert.h>

unsigned replace_byte(unsigned x, unsigned char b, int i)
{
    unsigned char* byte_pointer = (unsigned char*)&x;
    byte_pointer[i] = b;
    return x;
}

void test_01()
{
    assert(replace_byte(0x12345678, 0xAB, 2) == 0x12AB5678);
    assert(replace_byte(0x12345678, 0xAB, 0) == 0x123456AB);
    printf("Success!\n");
}

int main()
{
    test_01();
}

