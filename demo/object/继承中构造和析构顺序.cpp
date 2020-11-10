#include <iostream>

using namespace std;
//子类继承父类后，当创建子类对象，也会调用父类的构造函数
//继承中的构造和析构顺序
class B{
public:
    B(){
        cout << "B构造函数！" << endl;
    }
    ~B(){
        cout << "B析构函数！" << endl;
    }
};


class Base: public B{
public:
    Base(){
        cout << "Base构造函数！" << endl;
    }
    ~Base(){
        cout << "Base析构函数" << endl;
    }
};

class Son: public Base{
public:
    Son(){
        cout << "Son构造函数" << endl;
    }
    ~Son(){
        cout << "Son析构函数" << endl;
    }
};

void test01(){
//    Base b;
    Son s; // Base构造函数！
           // Son构造函数
           // Son析构函数
           // Base析构函数

};

int main() {
    test01();
    return 0;
}
