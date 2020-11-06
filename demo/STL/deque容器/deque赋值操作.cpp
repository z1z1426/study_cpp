#include <iostream>
#include <deque>

using namespace std;

template<class T>
void printDeque(const deque<T>&d){
    for (typename deque<T>::const_iterator it=d.begin();it!=d.end();it++){
        //*it = 100 //容器中的数据不可以修改了
        cout << *it << " ";
    }
    cout << endl;
}

//deque容器赋值操作
void test01(){
    deque<int>d1;
    for (int i=0;i<10;i++){
        d1.push_back(i);
    }
    printDeque(d1);
    //operator=赋值
    deque<int>d2;
    d2 = d1;
    printDeque(d2);
    //assign赋值
    deque<int>d3;
    d3.assign(d1.begin(), d1.end());
    printDeque(d3);
}

int main() {
    test01();
    return 0;
}
