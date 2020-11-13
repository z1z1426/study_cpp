#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void myPrint(int val){
    cout << val << " ";
}

void test01() {
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
}

//加随机数种子才能每次随机出不一样的值
int main() {
    srand((unsigned int)time(NULL));
    test01();
    return 0;
}
