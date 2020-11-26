#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test01() {
    short x = 32767;
    short y = 10;
    short z = 1000;
    printf("%d\n", sizeof(x+y+z));
    printf("%d", (short)(x+y+z));
}

int main() {
    test01();
    return 0;
}
