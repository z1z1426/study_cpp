//
// Created by ge on 2020/10/29.
//
#include <iostream>
using namespace std;

int *func(){
    //利用new关键字，可以将数据开辟到堆区
    //new返回的是该数据类型的指针
    //指针 本质也是局部变量，放在栈上，指针保存的数据是放在堆区
    int *p = new int(10);
    return p;
}

void test01(){
    //在堆区开辟数据
    int *p = func();
    cout << *p << endl;
    //堆区的数据由程序员管理开辟和释放
    //如果想释放堆区的数据，利用关键字delete
    delete p;
    cout << *p << endl;
}

void test02(){
    int *arr = new int[10]; //10代表数组有10个元素
    for (int i=0; i< 10; i++){
        arr[i] = i + 100;
    }
    for (int i=0;i<10;i++){
        cout << arr[i] << endl;
    }
    //释放堆取数组
    //释放数组的时候，要加[]才可以
    delete[] arr;
}

int main(){
    test01();
    return 0;
}
