#include <iostream>
#include <deque>
using namespace std;

//deque双端数组
//deque内部工作原理：
//deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
//中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间，deque容器的迭代器也是支持随机访问的
template<class T>
void printDeque(const deque<T>&d){
    for (typename deque<T>::const_iterator it=d.begin();it!=d.end();it++){
        //*it = 100 //容器中的数据不可以修改了
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    deque<int>d1;
    for (int i=0;i<10;i++){
        d1.push_back(i);
    }
    printDeque(d1);
    deque<int>d2(d1.begin(), d1.end());
    printDeque(d2);
    deque<int>d3(10, 100);
    printDeque(d3);
    deque<int>d4(d3);
    printDeque(d4);
}

int main() {
    test01();
    return 0;
}
