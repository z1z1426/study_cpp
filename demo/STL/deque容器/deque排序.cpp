#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

template<class T>
void printDeque(const deque<T>&d){
    for (typename deque<T>::const_iterator it=d.begin();it!=d.end();it++){
        //*it = 100 //容器中的数据不可以修改了
        cout << *it << " ";
    }
    cout << endl;
}

//deque容器排序
void test01() {
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    //300 200 100 10 20 30
    printDeque(d);
    //排序 默认排序规则 从小到大升序
    //对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
    //vector容器也可以利用sort进行排序
    sort(d.begin(), d.end());
    printDeque(d);
}

int main() {
    test01();
    return 0;
}
