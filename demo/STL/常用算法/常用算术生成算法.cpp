#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;
//1、accumulate，需要包含头文件numeric
//计算区间内容器元素累计总和
void test01() {
    vector<int>v;
    for(int i=0;i<=100;i++){
        v.push_back(i);
    }
    //参数3 起始累加值
    int num = accumulate(v.begin(), v.end(), 0);
    cout << "和为： " << num << endl;
}

void myPrint(int val){
    cout << val << " ";
}

//2、fill，向容器中填充想要的数据
void test02(){
    vector<int>v;
    v.resize(10);
    //后期重新填充
    fill(v.begin(), v.end(), 100);
    for_each(v.begin(), v.end(), myPrint);
}

int main() {
    test02();
    return 0;
}
