#include <iostream>
using namespace std;
//const修饰的是指针，指针指向可以改，指针指向的值不可以改
//const修饰的是常量，指针指向不可以改，指针指向的值可以改
//const既修饰指针又修饰常量，两个都不可以改。

int main() {
    int a = 10;
    int *p = &a;
    cout << "a的地址为" << p << endl;
    cout << sizeof(p) << endl;
    cout << sizeof(float *) << endl;
    return 0;
}
