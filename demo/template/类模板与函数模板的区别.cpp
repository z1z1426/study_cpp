#include <iostream>

using namespace std;

//区别主要有两点
//1、类模板没有自动类型推导的使用方式
//2、类模板在模板参数列表中可以有默认参数

template<class NameType, class AgeType = int>
class Person{
public:
    Person(NameType name, AgeType age){
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson(){
        cout << "name: " << this->m_Name << " age = " << this->m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

void test01(){
//    Person p("孙悟空", 1000); 错误，无法用自动类型推导
    Person<string, int> p("孙悟空", 1000); //正确，只能用显示指定类型
    p.showPerson();
}

void test02(){
    Person<string> p("猪八戒", 999);
    p.showPerson();
}

int main() {
    test01();
    test02();
    return 0;
}
