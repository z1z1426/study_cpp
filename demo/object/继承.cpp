#include <iostream>

using namespace std;
//继承实现页面
//公共页面类
//继承的好处可以减少重复的代码
//派生类的成员包含两大部分，一类是从基类继承过来的，一类是自己增加的成员。各体现共性和个性。
class BasePage{
public:
    void header(){
        cout << "首页" << endl;
    }
    void footer(){
        cout << "页脚" << endl;
    }
    void left(){
        cout << "导航栏" << endl;
    }
    void content(){
        cout << "内容" << endl;
    }
};

class Java: public BasePage{
public:
    void content(){
        cout << "Java学科视频" << endl;
    }
};

class Python: public BasePage{
public:
    void content(){
        cout << "Python学科视频" << endl;
    }
};

class CPP: public BasePage{
public:
    void content(){
        cout << "C++学科视频" << endl;
    }
};

void test01(){
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
}

int main() {
    test01();
    return 0;
}
