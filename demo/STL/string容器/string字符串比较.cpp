#include <iostream>

using namespace std;
//字符串比较
//主要比较两个字符串是否相等
void test01(){
    string str1 = "xello";
    string str2 = "hello";
    if (str1.compare(str2) == 0){
        cout << "str1等于str2" << endl;
    }
    else if(str1.compare(str2) > 0){
        cout << "str1大于str2" << endl;
    }
    else {
        cout << "str1小于str2" << endl;
    }
}
int main() {
    test01();
    return 0;
}
