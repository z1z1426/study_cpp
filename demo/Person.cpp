#include <iostream>

using namespace std;

class Person{
public:
    int age;
    //构造函数，在对象初始化时调用,可以重载
    Person(){
        cout << "Person无参构造函数" << endl;
    }

    Person(int a){
        age = a;
        cout << "Person有参构造函数" << endl;
    }

    //拷贝构造函数
    Person(const Person &p){
        //将传入的人身上的所有属性，拷贝到我身上
        age = p.age;
        cout << "Person拷贝构造函数" << endl;
    }

    //析构函数，在类对象即将销毁时执行
    ~Person(){
        cout << "Person析构函数" << endl;
    }
};

void test01(){
    //构造函数调用
    //1、括号法
    Person p;//默认构造函数调用
    Person p2(10);
    Person p3(p2);
    //注意事项
    //调用默认构造函数时候，不要加()
    //因为下面这行代码，编译器会认为是一个函数的声明，不会认为在创建对象
    //Person p1();
    //2、显示法
    Person p4;
    Person p5 = Person(10);//有参构造
    //Person(10)；匿名对象，当前行执行结束后，系统会立即回收掉匿名对象
    //不要利用拷贝构造函数，初始化匿名对象编译器会认为Person(p3)===Person p3
    //3、隐式转换法
    Person p6 = 10; //相当于写了Person p6 = Person(10)
    Person p7 = p6; //拷贝构造
}

int main() {
    test01();
    return 0;
}
