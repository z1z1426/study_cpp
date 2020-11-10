#include <iostream>
#include <map>

using namespace std;
//map容器 大小和交换
template<class T1, class T2>
void printMap(map<T1, T2>&s){
    for (typename map<T1, T2>::iterator it=s.begin();it!=s.end();it++){
        cout << "key = " << (*it).first << " value = " << it->second << endl;
    }
    cout << endl;
}
//大小
void test01() {
    map<int, int>m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    if(m.empty()){
        cout << "m为空" << endl;
    } else{
        cout << "m不为空" << endl;
        cout << "m的大小为： " << m.size() << endl;
    }
}

//交换
void test02(){
    map<int, int>m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    map<int, int>m2;
    m2.insert(pair<int, int>(4, 100));
    m2.insert(pair<int, int>(5, 200));
    m2.insert(pair<int, int>(6, 300));
    cout << "交换前: " << endl;
    printMap(m);
    printMap(m2);
    cout << "交换后: " << endl;
    m.swap(m2);
    cout << "交换后： " << endl;
    printMap(m);
    printMap(m2);
}

int main() {
    test02();
    return 0;
}
