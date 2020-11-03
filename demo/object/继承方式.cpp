#include <iostream>

using namespace std;
//继承方式
//公共继承
class Base1{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Base2{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Base3{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son1: public Base1{
public:
    void func(){
        m_A = 10; //父类中的公共权限成员 到子类中依然是公共权限
        m_B = 10; //父类中的保护权限成员 到子类中依然是保护权限
        //m_C = 10; //父类中的私有权限成员 子类访问不到
    }
};

class Son2: protected Base2{
public:
    void func(){
        m_A = 100; // 父类中公共成员，到子类中变为保护权限
        m_B = 100; // 父类中保护成员 到子类中变为保护权限
//        m_C = 100; //父类中私有成员 子类访问不到
    }
};

class Son3: private Base3{
public:
    void func(){
        m_A = 100; // 父类中公共成员变为私有权限
        m_B = 100; // 父类中保护成员变为私有权限
//        m_C = 100; // 父类中私有成员 子类依然访问不到
    }
};

class GrandSon3: public Son3{
public:
    void func(){
//        m_A = 1000; //父类私有属性子类访问不到
//        m_B = 1000; //父类私有属性子类访问不到
    }
};

void test01(){
//    Son1 s1;
//    s1.m_A = 100;
//    s1.m_B = 100; //到Son1中 m_B是保护权限，类外访问不到
    cout << "sizeof Son = " << sizeof(Son1) << endl;
    cout << "sizeof Son = " << sizeof(Son2) << endl;
    cout << "sizeof Son = " << sizeof(Son3) << endl;
}

void test02(){
    Son2 s2;
//    s2.m_A = 100; //在Son2中m_A变为保护权限，因此类外访问不到
}

void test03(){
    Son3 s3;
//    s3.m_A = 100; //在Son3中m_A变为私有权限，类外访问不到
}

int main() {
    test01();
    return 0;
}
