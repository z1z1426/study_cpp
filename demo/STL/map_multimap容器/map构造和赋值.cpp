#include <iostream>
#include <map>
using namespace std;

template<class T1, class T2>
void printMap(map<T1, T2>&s){
    for (typename map<T1, T2>::iterator it=s.begin();it!=s.end();it++){
        cout << "key = " << (*it).first << " value = " << it->second << endl;
    }
    cout << endl;
}

void test01() {
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    printMap(m);
    //拷贝构造
    map<int, int>m2(m);
    printMap(m2);
    //赋值
    map<int, int>m3;
    m3 = m2;
    printMap(m3);
}

int main() {
    test01();
    return 0;
}
