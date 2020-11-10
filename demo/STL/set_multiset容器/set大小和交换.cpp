#include <iostream>
#include <set>
using namespace std;

template<class T>
void printSet(set<T>&s){
    for (typename set<T>::iterator it=s.begin();it!=s.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    set<int>s1;
    //插入数据只有insert方式
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(30);
    printSet(s1);
    //判断是否为空
    if(s1.empty()){
        cout << "s1为空" << endl;
    } else{
        cout << "s1不为空" << endl;
    }
    cout << s1.size() << endl;
    set<int>s2;
    //插入数据
    s2.insert(100);
    s2.insert(200);
    s2.insert(300);
    s2.insert(400);
    cout << "交换前： " << endl;
    printSet(s1);
    printSet(s2);
    cout << "交换后： " << endl;
    s1.swap(s2);
    printSet(s1);
    printSet(s2);
}

int main() {
    test01();
    return 0;
}
