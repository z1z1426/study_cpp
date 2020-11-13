#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//两个容器元素合并，并存储到另一个容器中
//两个容器必须是同序的
//merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest_beg);

void myPrint(int val){
    cout << val << " ";
}

void test01() {
    vector<int>v1;
    vector<int>v2;
    for(int i=0;i<10;i++){
        v1.push_back(i);
        v2.push_back(i+1);
    }
    //目标容器
    vector<int>vTarget;
    //提前给目标容器分配空间
    vTarget.resize(v1.size()+v2.size());
    //合并，需要两个有序序列
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), myPrint);
    cout << endl;
}

int main() {
    test01();
    return 0;
}
