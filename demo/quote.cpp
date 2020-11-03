#include <iostream>
using namespace std;

void test1() {
    //引用基本语法
    //数据类型 &别名 = 原名
    //引用必须要初始化，且初始化后就不可以更改。
    int a = 10;
    int &b = a;
    cout << a << endl;
}

//交换函数
void myswap01(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void myswap02(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void myswap03(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 10;
    int b = 20;
    //myswap01(a, b);
    //myswap02(&a, &b);
    myswap03(a, b); //引用传递，形参会修饰实参
    cout << "a=" << a;
    cout << "b=" << b;
}
