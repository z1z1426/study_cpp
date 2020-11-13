#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//bool binary_search(iterator beg, iterator end, value)
//必须在有序序列下使用，查找指定的元素，查到返回true否则flase
void test01() {
    vector<int> v;
    for(int i=1;i<10;i++){
        v.push_back(i);
    }
    bool it = binary_search(v.begin(), v.end(), 9);
    if (it){
        cout << "查找到了" << endl;
    }else{
        cout << "未查找到" << endl;
    }
}

int main() {
    test01();
    return 0;
}
