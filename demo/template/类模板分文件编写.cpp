#include <iostream>

using namespace std;

//第一种解决方式 直接包含源文件
#include "person.hpp"
//第二种解决方式，将.h和.cpp中的内容写到一起，将后缀名改为.hpp文件
//主流用第二种

void test01(){
    Person<string, int>p("Jerry", 18);
    p.showPerson();
}

int main() {
    test01();
    return 0;
}
