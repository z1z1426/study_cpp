#include <iostream>
#include <list>

using namespace std;
//list容器构造函数

template<class T>
void printList(const list<T>&L){
    for(typename list<T>::const_iterator it = L.begin();it!=L.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    list<int>L1;
    //添加数据
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    //遍历容器
    printList(L1);
    //区间方式构造
    list<int>L2(L1.begin(), L1.end());
    printList(L2);
    //拷贝构造
    list<int>L3(L2);
    printList(L3);
    //n个elem
    list<int>L4(10, 1000);
    printList(L4);
}

int main() {
    test01();
    return 0;
}
