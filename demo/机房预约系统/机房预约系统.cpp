#include <iostream>
#include <fstream>
#include "identity.h"
#include "globalFile.h"
#include "student.h"
#include "student.cpp"
#include "teacher.h"
#include "teacher.cpp"
#include "manager.h"
#include "manager.cpp"

using namespace std;

//管理员菜单
void managerMenu(Identity * &manager){
    while(true){
        //管理员菜单
        manager->operMenu();
        Manager* man = (Manager*)manager;
        int select = 0;
        cin >> select;
        if(select == 1){//添加账号
            cout << "添加账号" << endl;
            man->addPerson();
        }
        else if(select == 2){//查看账号
            cout << "查看账号" << endl;
            man->showPerson();
        }
        else if(select == 3){//查看机房
            cout << "查看机房" << endl;
            man->showComputer();
        }
        else if(select == 4){//清空预约
            cout << "清空预约" << endl;
            man->cleanFile();
        }
        else{
            delete manager;
            cout << "注销成功" << endl;
            pause();
            return;
        }
    }
}


//登录功能
void LoginIn(string fileName, int type){
    //父类指针，用于指向子类对象
    Identity *person = NULL;
    //读文件
    ifstream ifs;
    ifs.open(fileName, ios::in);
    //判断文件是否存在
    //文件不存在情况
    if(!ifs.is_open()){
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }
    //准备接受用户的信息
    int id = 0;
    string name;
    string pwd;
    //判断身份
    if(type == 1){//学生身份
        cout << "请输入你的学号： " << endl;
        cin >> id;
    } else if(type==2){
        cout << "请输入你的职工号： " << endl;
        cin >> id;
    }
    cout << "请输入用户名： " << endl;
    cin >> name;
    cout << "请输入密码： " << endl;
    cin >> pwd;
    string a;
    if(type==1){
        //学生身份验证
        int fId; //从文件中读取的id号
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd){
            //与用户输入的信息作对比
            if (fId == id && fName == name && fPwd == pwd){
                cout << "学生" << fName << "验证登录成功！" << endl;
                cout << "按任意键回车继续" << endl;
                cin >> a;
                person = new Student(id, name, pwd);
                //进入学生子菜单
                studentMenu(person);
                return;
            }
        }
    }else if(type==2){
        //教师身份验证
        int fId; //从文件中读取的id号
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            //与用户输入的信息作对比
            if (fId == id && fName == name && fPwd == pwd) {
                cout << "教师" << fName << "验证登录成功！" << endl;
                cout << "按任意键回车继续" << endl;
                cin >> a;
                person = new Teacher(id, name, pwd);
                TeacherMenu(person);
                return;
            }
        }
    }else if(type==3){
        //管理员身份验证
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd) {
            //与用户输入的信息作对比
            if (fName == name && fPwd == pwd) {
                cout << "管理员" << fName << "验证登录成功！" << endl;
                cout << "按任意键回车继续" << endl;
                cin >> a;
                person = new Manager(name, pwd);
                //进入管理员子菜单
                managerMenu(person);
                return;
            }
        }
    }
    cout << "验证登录失败!" << endl;
    return;
}


int main() {
    int select = 0; //用于接受用户的选择
    int pause; //用于暂停界面
    while(true){
        cout << "==============================欢迎来到机房预约系统==========================" << endl;
        cout << endl << "请输入您的身份" << endl;
        cout << "\t\t ----------------------------------------------------------\n";
        cout << "\t\t|                                                          |\n";
        cout << "\t\t|                      1、学生代表                           |\n";
        cout << "\t\t|                                                          |\n";
        cout << "\t\t|                      2、老   师                           |\n";
        cout << "\t\t|                                                          |\n";
        cout << "\t\t|                      3、管 理 员                           |\n";
        cout << "\t\t|                                                          |\n";
        cout << "\t\t|                      0、退  出                            |\n";
        cout << "\t\t|                                                          |\n";
        cout << "\t\t ----------------------------------------------------------\n";
        cout << "输入您的选择: " << endl;
        cin >> select; //接受用户选择
        switch (select) {
            case 1://学生身份
                LoginIn(STUDENT_FILE, 1);
                break;
            case 2://老师身份
                LoginIn(TEACHER_FILE, 2);
                break;
            case 3://管理员身份
                LoginIn(ADMIN_FILE, 3);
                break;
            case 0://退出系统
                cout << "欢迎下次使用" << endl;
                return 0;
            default:
                cout << "输入有误，输入任意键并回车返回！" << endl;
                cin >> pause;
                break;
        }
    }

    return 0;
}
