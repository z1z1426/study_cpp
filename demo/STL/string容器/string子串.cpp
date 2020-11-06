#include <iostream>

using namespace std;
//string求子串
void test01(){
    string str = "abcdef";
    string subStr = str.substr(1, 3);
    cout << "subStr = " << subStr << endl;
}

//实用操作
void test02(){
    string email = "hello@sina.com";
    //从邮件地址中 获取用户名信息
    int pos = email.find('@');
    string usrName = email.substr(0, pos);
    cout << usrName << endl;
}

int main() {
    // test01();
    test02();
    return 0;
}
