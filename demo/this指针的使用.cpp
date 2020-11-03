#include <iostream>

using namespace std;
class Person{
public:
    Person(int age){
        this->age = age;
    }
    int age;
    Person& PersonAddAge(Person p2){
        this->age += p2.age;
        return *this;
    }
};

void test03();

void test01(){
    Person p1(18);
    cout << "p1的年龄为： " << p1.age << endl;
}

void test02(){
    Person p1(10);
    Person p2(10);
    p1.PersonAddAge(p2).PersonAddAge(p2).PersonAddAge(p2);
    cout << p1.age << endl;
}

 //1.解决名称冲突
 //2.返回对象本身用*this
int main() {
    test03();
    return 0;
}

void test03() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = arr;
    for (int i=0;i<10;i++){
        cout<<*p++<<endl;
    }
}
