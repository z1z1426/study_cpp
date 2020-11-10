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
    set<int> s1;
    //插入数据只有insert方式
    s1.insert(30);
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    printSet(s1);
    //删除
    s1.erase(s1.begin());
    printSet(s1);
    //删除重载版本
    s1.erase(30);
    printSet(s1);
    //清空
    s1.erase(s1.begin(), s1.end());
    //s1.clear();
}

int main() {
    test01();
    return 0;
}
