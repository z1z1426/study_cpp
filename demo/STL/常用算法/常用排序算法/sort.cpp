#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void myPrint(int val){
    cout << val << " ";
}
//sort(iterator beg, iterator end, _Pred) //对容器内元素进行排序，默认是从小到大
void test01() {
    vector<int>v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);
    //利用sort进行升序
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    //改变为降序
    sort(v.begin(), v.end(), greater<int>());
    cout << endl;
    for_each(v.begin(), v.end(), myPrint);
}

int main() {
    test01();
    return 0;
}
