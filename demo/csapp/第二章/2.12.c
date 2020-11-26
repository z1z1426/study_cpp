#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test01() {
    short int v = -12345;
    unsigned short uv = (unsigned short)v;
    printf("v = %d, uv = %u\n", v, uv);

}

int main() {
    test01();
    return 0;
}
