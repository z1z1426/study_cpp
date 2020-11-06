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

void test01(){
    deque<int>d1;
    for(int i=0;i<10;i++){
        d1.push_back(i);
    }
    printDeque(d1);
    if(d1.empty()){
        cout << "d1为空" << endl;
    }else{
        cout << "d1不为空" << endl;
        cout << "d1的大小为： " << d1.size() << endl;
        //deque容器没有容量概念
    }
    //重新指定大小
//    d1.resize(15);
    d1.resize(15, 1);
    printDeque(d1);
    d1.resize(5);
    printDeque(d1);
}

//总结：
//deque没有容量概念
//empty()判断是否为空
//size返回元素个数
//resize重新指定个数
int main() {
    test01();
    return 0;
}
