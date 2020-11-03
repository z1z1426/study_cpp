#include <iostream>

using namespace std;

//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量

class Person{
public:
    static void func(){
        m_A = 100; //静态成员函数可以访问 静态成员变量
        // m_B = 200; //静态成员函数不可以访问非静态成员变量，这是因为无法区分到底是哪个对象调用修改
        cout << "访问静态成员函数" << endl;
    }
    static int m_A;
    int m_B;
    //静态成员函数也是有访问权限的
private:
    static void func2(){
        cout << "static void func2调用" << endl;
    }
};

//必须在类外初始化
int Person::m_A = 0;

//有两种访问方式
void test01(){
    //1、通过对象访问
    Person p;
    p.func();
    //2、通过类名访问
    Person::func();
}

int main() {
    test01();
    return 0;
}
