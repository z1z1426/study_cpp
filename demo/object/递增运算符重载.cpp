#include <iostream>

using namespace std;

//重载递增运算符
//自定义整型
class MyInteger{
    friend ostream &operator<<(ostream &cout, MyInteger myint);
public:
    MyInteger(){
        m_Num = 0;
    }
    //重载前置++运算符 返回引用为了一直对一个数据进行递增操作
    MyInteger &operator++(){
        m_Num++;
        return *this;
    }
    //重载后置++运算符
    //void operator++(int) int代表占位参数，可以用于区分前置和后置递增
    MyInteger operator++(int){
        //先记录当时结果
        MyInteger temp = *this;
        //后递增
        m_Num++;
        //最后将记录结果做返回
        return temp;
    }

private:
    int m_Num;
};

//重载<<运算符
ostream &operator<<(ostream &cout, MyInteger myint){
    cout << myint.m_Num;
    return cout;
}

void test01(){
    MyInteger myint;
    cout << ++myint << endl;
}

void test02(){
    MyInteger myint;
    cout << myint++ << endl;
    cout << myint << endl;
}
//前置运算符返回引用，后置运算符返回值
int main() {
    test01();
    test02();
    return 0;
}
