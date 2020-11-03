#include <iostream>

using namespace std;

class Student{
public:
    //属性
    string name;
    int id;
    //行为
    void setName(string name){
        this->name = name;
    }
    void showStudent(){
        cout << "姓名：" << name << " 学号：" << id << endl;
    }
};

int main() {
    //创建一个具体学生 实例化对象
    Student s1;
    s1.setName("张三");
    s1.id = 1;
    s1.showStudent();
    return 0;
}
