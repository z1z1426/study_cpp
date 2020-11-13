#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//find_if(iterator beg, iterator end, _Pred); //按值查找元素，找到返回指定位置迭代器，
                                              // 找不到返回结束迭代器位置，_Pred函数或者谓词返回bool类型仿函数

//1、查找内置数据类型

class GreaterFive{
public:
    bool operator()(int val){
        return val > 5;
    }
};

void test01() {
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it==v.end()){
        cout << "没有找到" << endl;
    }else{
        cout << "找到大于5的数字为： " << *it << endl;
    }
}

//2、查找自定义数据类型
class Person{
public:
    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

class Greater20{
public:
    bool operator()(Person &p){
        return p.m_Age > 20;
    }
};

void test02(){
    vector<Person>v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    //找年龄大于20的人
    vector<Person>::iterator it = v.begin();
    vector<Person>::iterator it1;
    do{
        it1 = find_if(it, v.end(), Greater20());
        if (it1 == v.end()){
            cout << "没有找到" << endl;
            break;
        }else{
            cout << "找到了，姓名： " << it1->m_Name << " 年龄： " << it1->m_Age << endl;
            it = ++it1;
        }
    }while (it!=v.end());


}

int main() {
    test02();
    return 0;
}
