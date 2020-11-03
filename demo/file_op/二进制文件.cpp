#include <iostream>
#include <fstream>
using namespace std;
//打开方式要指定为ios::binary

class Person{
public:
    char m_Name[64];
    int m_Age;
};

void test01(){
    //1、包含头文件
    //2、创建流对象
//    ofstream ofs;
    ofstream  ofs("person.txt", ios::out | ios::binary);
    //3、打开文件
//    ofs.open("person.txt", ios::out | ios::binary);
    //4、写文件
    Person p ={"张三", 18};
    ofs.write((const char *)&p, sizeof(Person));
    //5、关闭文件
    ofs.close();
}

void test02(){
    //1、包含头文件
    //2、创建流对象
    ifstream ifs;
    //3、打开文件 判断文件是否打开成功
    ifs.open("person.txt", ios::in | ios::binary);
    if (!ifs.is_open()){
        cout << "文件打开失败" << endl;
        return;
    }
    //4、读文件
    Person p;
    ifs.read((char *)&p, sizeof(Person));
    cout << "姓名: " << p.m_Name << " 年龄: " << p.m_Age << endl;
    //5、关闭文件
}

int main() {
    test02();
    return 0;
}
