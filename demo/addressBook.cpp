//
// Created by ge on 2020/10/29.
//
# include <iostream>
#include <sys/param.h>
#define MAX_P 1000

using namespace std;

struct Person{
    string name;
    int sex;
    int age;
    string phone;
    string address;
};

struct Addressbooks{
    Person persons[MAX_P];
    int size;
};

void addPerson(Addressbooks *abs);

void showPerson(Addressbooks *abs);

void deletePerson(Addressbooks *abs);

int isExist(Addressbooks *abs, string name);

int findPerson(Addressbooks *abs);

void alterPerson(Addressbooks *abs);

void cleanPerson(Addressbooks *abs);

//菜单界面
void showMenu(){
    cout << "*****************************" << endl;
    cout << "*****    1、添加联系人    *****"<< endl;
    cout << "*****    2、显示联系人    *****"<< endl;
    cout << "*****    3、删除联系人    *****"<< endl;
    cout << "*****    4、查找联系人    *****"<< endl;
    cout << "*****    5、修改联系人    *****"<< endl;
    cout << "*****    6、清空联系人    *****"<< endl;
    cout << "*****    0、退出通讯录    *****"<< endl;
    cout << "*****************************" << endl;
}

int main(){
    Addressbooks abs;
    abs.size = 0;
    int select = 0;
    while (true){
        showMenu();
        cin >> select;
        switch (select) {
            case 1: //添加联系人
                addPerson(&abs);
                break;
            case 2: //显示联系人
                showPerson(&abs);
                break;
            case 3: //删除联系人
                deletePerson(&abs);
                break;
            case 4: //查找联系人
                findPerson(&abs);
                break;
            case 5: //修改联系人
                alterPerson(&abs);
                break;
            case 6: //清空联系人
                cleanPerson(&abs);
                break;
            case 0: //退出通讯录
                cout << "欢迎下次使用" << endl;
                return 0;
            default:
                break;
        }
    }
}

void cleanPerson(Addressbooks *abs) {
    abs->size = 0;
    cout << "通讯录已清空" << endl;
}

void alterPerson(Addressbooks *abs) {
    int res = findPerson(abs);
    string name;
    cout << "请输入姓名： " << endl;
    cin >> name;
    abs->persons[res].name = name;
    // 性别
    cout << "请输入性别： " << endl;
    cout << "1 --- 男" << endl;
    cout << "2 --- 女" << endl;
    int sex = 0;
    while(true) {
        cin >> sex;
        if (sex == 1 || sex == 2) {
            abs->persons[res].sex = sex;
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }
    //年龄
    cout << "请输入年龄： " << endl;
    int age = 0;
    cin >> age;
    abs->persons[res].age = age;
    //电话
    cout << "请输入电话： " << endl;
    string phone;
    cin >> phone;
    abs->persons[res].phone = phone;
    //住址
    cout << "请输入住址： " << endl;
    string address;
    cin >> address;
    abs->persons[res].address = address;
    //更新通讯录人数
    cout << "修改成功" << endl;
}

int findPerson(Addressbooks *abs) {
    cout << "请输入要操作的人名字：" << endl;
    string name;
    cin >> name;
    int res = isExist(abs, name);
    if (res==-1){
        cout << "查无此人" << endl;
    }
    else{
        string sex;
        sex = abs->persons[res].sex == 1 ? "男" : "女";
        cout << "姓名：" << abs->persons[res].name << " " << "性别：" << sex << " " << "年龄：" << abs->persons[res].age
             << " " << "联系电话:" << abs->persons[res].phone << " " << "住址：" << abs->persons[res].address << endl;
    }
    return res;
}

void deletePerson(Addressbooks *abs) {
    cout << "请输入待删除联系人的姓名：" << endl;
    string name;
    cin >> name;
    int res = isExist(abs, name);
    if (res==-1){
        cout << "查无此人" << endl;
    }
    else{
        for(int i=res;i<abs->size;i++){
            abs->persons[i] = abs->persons[i+1];
        }
        abs->size--;
        cout << "删除成功" << endl;
    }
}

void showPerson(Addressbooks *abs) {
    if(abs->size==0){
        cout << "当前记录为空" << endl;
    }
    else {
        for (int i = 0; i < abs->size; i++) {
            string sex;
            sex = abs->persons[i].sex == 1 ? "男" : "女";
            cout << "姓名：" << abs->persons[i].name << " " << "性别：" << sex << " " << "年龄：" << abs->persons[i].age
                 << " " << "联系电话:" << abs->persons[i].phone << " " << "住址：" << abs->persons[i].address << endl;
        }
    }
}

void addPerson(Addressbooks *abs) {
    if(abs->size==MAX_P){
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }
    else{
        string name;
        cout << "请输入姓名： " << endl;
        cin >> name;
        abs->persons[abs->size].name = name;
        // 性别
        cout << "请输入性别： " << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int sex = 0;
        while(true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->persons[abs->size].sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }
        //年龄
        cout << "请输入年龄： " << endl;
        int age = 0;
        cin >> age;
        abs->persons[abs->size].age = age;
        //电话
        cout << "请输入电话： " << endl;
        string phone;
        cin >> phone;
        abs->persons[abs->size].phone = phone;
        //住址
        cout << "请输入住址： " << endl;
        string address;
        cin >> address;
        abs->persons[abs->size].address = address;
        //更新通讯录人数
        abs->size++;
        cout << "添加成功" << endl;
    }
}

int isExist(Addressbooks *abs, string name){
    for (int i=0;i< abs->size;i++){
        if (abs->persons[i].name == name){
            return i;
        }
    }
    return -1;
}
