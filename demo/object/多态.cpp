#include <iostream>

//静态多态和动态多态区别:
//1、静态多态的函数地址早绑定-编译阶段确定函数地址
//2、动态多态的函数地址晚绑定-运行阶段确定函数地址

using namespace std;
//多态
//动物类
class Animal{
public:
    //虚函数
    virtual void speak(){
        cout << "动物在说话" << endl;
    }
};
//猫类
class Cat: public Animal{
public:
    //重写 函数返回值类型 函数名 参数列表 完全相同
    void speak(){
        cout << "小猫在说话" << endl;
    }
};
//当子类重写父类的虚函数
//子类中的虚函数表内部会替换成子类的虚函数地址
class Dog: public Animal{
public:
    void speak(){
        cout << "小狗在说话" << endl;
    }
};

//执行说话的函数
//地址早绑定 在编译阶段确定函数地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定
//动态多态满足条件
//1、有继承关系
//2、子类重写父类的虚函数
//动态多态使用
//父类的指针或者引用 执行子类对象
void doSpeak(Animal &animal){//Animal &animal = cat;
    animal.speak();
}

void test01(){
    Cat cat;
    doSpeak(cat);
    Dog dog;
    doSpeak(dog);
}

int main() {
    test01();
    return 0;
}
