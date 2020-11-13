#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//掌握常用的集合算法
//set_intersection //求两个容器的交集
//set_union //求两个容器的并集
//set_difference //求两个容器的差集

void myPrint(int val){
    cout << val << " ";
}
//获取交集
void test01() {
    vector<int>v1;
    vector<int>v2;
    for(int i=0;i<10;i++){
        v1.push_back(i);
        v2.push_back(i+5);
    }

    vector<int>vTarget;
    //目标容器需要提前开辟空间
    //最特殊情况 大容器包含小容器 开辟空间 取小容器的size即可
    vTarget.resize(min(v1.size(), v2.size()));
    //获取交集
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint);
}
//并集
void test02(){
    vector<int>v1;
    vector<int>v2;
    for(int i=0;i<10;i++){
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int>vTarget;
    vTarget.resize(v1.size()+v2.size());
    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint);
}
//差集
void test03(){
    vector<int>v1;
    vector<int>v2;
    for(int i=0;i<10;i++){
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int>vTarget;
    vTarget.resize(min(v1.size(), v2.size()));
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint);
}

int main() {
    test03();
    return 0;
}
