#include <iostream>

using namespace std;
//函数原型
//string& insert(int pos, const char* s); //插入字符串
//string& insert(int pos, const string& str); //插入字符串
//string& insert(int pos, int n, char c) //在指定位置插入n个字符c
//string& erase(int pos, int n=npos); //删除从Pos开始的n个字符

//对string字符串进行插入和删除操作
void test01(){
    string str = "hello";
    //插入
    str.insert(1, "111");
    //h111ello
    cout << "str = " << str << endl;
    //删除
    str.erase(1, 3);
    cout << "str = " << str << endl;
}
//插入和删除的起始下标都是从0开始
int main() {
    test01();
    return 0;
}
