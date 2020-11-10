#include <iostream>
#include <list>

using namespace std;

template<class T>
void printList(const list<T>&L){
    for(typename list<T>::const_iterator it = L.begin();it!=L.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}

//list容器大小操作
void test01() {
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);
    //判断容器是否为空
    if(L1.empty()){
        cout << "L1为空" << endl;
    }else{
        cout << "L1不为空" << endl;
        cout << "L1的元素个数为： " << L1.size() << endl;
    }
    //重新指定大小
    L1.resize(10, 10000);
    printList(L1);
    L1.resize(2);
    printList(L1);
}

int main() {
    test01();
    return 0;
}


// 枯坐台前杂念多
// 蓦然思君恍如昨
// 尔来韶华匆匆去
// 缘灭何从有言说