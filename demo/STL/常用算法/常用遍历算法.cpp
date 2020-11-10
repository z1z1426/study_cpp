#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//常用遍历算法for_each
//实际开发最常用，需要熟练掌握

//普通函数
void print01(int val){
    cout << val << " ";
}

//仿函数
class print02{
public:
    void operator()(int val){
        cout << val << " ";
    }
};

//for_each
void test01() {
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), print01);
    cout << endl;
    for_each(v.begin(), v.end(), print02());
}

class Transform{
public:
    int operator()(int v){
        return v;
    }
};

//transform
void test02(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    vector<int>vTarget;//目标容器
    vTarget.resize(v.size()); //目标容器需要提前开辟空间
    transform(v.begin(), v.end(), vTarget.begin(), Transform());
    for_each(vTarget.begin(), vTarget.end(), print02());
}

int main() {
//    test01();
    test02();
    return 0;
}
