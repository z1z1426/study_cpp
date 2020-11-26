#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test01() {
    int x = 0x7fffffff;
    printf("%d\n", x);
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(float));
    printf("%d", (int)(float)x);
}

void inplace_swap(int *x, int *y){
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
//    printf("%d %d", *x, *y);
}

void reverse_array(int a[], int cnt){
    int first, last;
    for(first=0, last=cnt-1;first<last;first++, last--){
        inplace_swap(&a[first], &a[last]);
    }
}

int main() {
//    test01();
//    int a = 10, b = 20;
//    int *x = &a, *y = &b;
//    inplace_swap(x, y);
    int a[] = {10, 20, 30, 40};
    int len = sizeof(a)/sizeof(a[0]);
    reverse_array(a, len);
    for (int i = 0; i < len; ++i) {
        printf("%d\n", a[i]);
    }
    return 0;
}
