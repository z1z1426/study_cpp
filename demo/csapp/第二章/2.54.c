#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test01() {
    //B
    int x = 0x7fffffff;
    float d = 555.55;
    printf("%d\n", x);
    printf("%d\n", (int)(float)x);
    printf("%f", (float)(double)d);
}

int main() {
    test01();
    return 0;
}
