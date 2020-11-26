#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test01() {
//    printf("%x", ~0xff);
    int x = 0x0fffff00;

//    if(!~x || !x || (!~(x|~0xff))||(!(x >> ((sizeof(int) - 1) << 3)))){
    if (!~x || !x || (!~(x|~0xff)) || (!(x >> (sizeof(int)-1) << 3))){
        printf("1");
    } else{
        printf("0");
    }
}

int main() {
    test01();
    return 0;
}
