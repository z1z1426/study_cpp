#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//查找相邻重复元素
void test01() {
    vector<int>v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);
    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    if (pos == v.end()){
        cout << "未找到相邻重复元素" << endl;
    }else{
        cout << "找到相邻重复元素: " << *pos << endl;
    }
}

int main() {
    test01();
    return 0;
}
