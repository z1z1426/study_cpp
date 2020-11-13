#include <iostream>
#include <algorithm>
#include "manager.h"
using namespace std;

Manager::Manager(){

}
Manager::Manager(string name, string pwd){
    this->m_Name = name;
    this->m_Pwd = pwd;
    //初始化容器
    this->initVector();
    //获取机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    ComputerRoom c;
    while(ifs >> c.m_ComId && ifs >> c.m_MaxNum){
        vCom.push_back(c);
    }
    cout << "当前机房数量为： " << vCom.size() << endl;
    ifs.close();
}

//初始化容器
void Manager::initVector() {
    //读取学生文件中信息
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if(!ifs.is_open()){
        cout << "文件读取失败" << endl;
        return;
    }
    vStu.clear();
    vTea.clear();
    Student s;
    while(ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd){
        vStu.push_back(s);
    }
    cout << "当前学生数量为： " << vStu.size() << endl;
    ifs.close(); //学生初始化
    //读取老师文件信息
    ifs.open(TEACHER_FILE, ios::in);
    Teacher t;
    while(ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd){
        vTea.push_back(t);
    }
    cout << "当前教师数量为： " << vTea.size() << endl;
    ifs.close();
}

//选择菜单
void Manager::operMenu(){
    cout << "欢迎管理员： " << this->m_Name << "登录！" << endl;
    cout << "\t\t ----------------------------------------------------------\n";
    cout << "\t\t|                                                          |\n";
    cout << "\t\t|                      1、添加账号                           |\n";
    cout << "\t\t|                                                          |\n";
    cout << "\t\t|                      2、查看账号                           |\n";
    cout << "\t\t|                                                          |\n";
    cout << "\t\t|                      3、查看机房                           |\n";
    cout << "\t\t|                                                          |\n";
    cout << "\t\t|                      4、清空预约                           |\n";
    cout << "\t\t|                                                          |\n";
    cout << "\t\t|                      0、注销登录                           |\n";
    cout << "\t\t|                                                          |\n";
    cout << "\t\t ----------------------------------------------------------\n";
    cout << "请选择您的操作: " << endl;
}
//添加账号
void Manager::addPerson(){
    cout << "请输入添加账号的类型： " << endl;
    cout << "1、添加学生" << endl;
    cout << "2、添加老师" << endl;
    string fileName;
    string tip;
    ofstream ofs;
    int select = 0;
    cin >> select;
    if (select == 1){
        fileName = STUDENT_FILE;
        tip = "请输入学号： ";
    }else{
        fileName = TEACHER_FILE;
        tip = "请输入职工编号： ";
    }
    //利用追加的方式写文件
    bool flag = false;
    int id;
    string name;
    string pwd;
    cout << tip << endl;
    do{
        cin >> id;
        if (checkRepeat(id, select)){
            cout << "该账号已存在！" << endl;
            cout << "0.重新输入新账号" << endl;
            cout << "1.返回主界面" << endl;
            int select1;
            cin >> select1;
            if (!select1){
                flag = true;
                cout << tip << endl;
            }else{
                ofs.close();
                return;
            }
        }else{
            flag = false;
        }
    }while(flag);
    ofs.open(fileName, ios::out | ios::app);
    cout << "请输入姓名： " << endl;
    cin >> name;
    cout << "请输入密码: " << endl;
    cin >> pwd;
    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功" << endl;
    ofs.close();
    //调用初始化容器接口，重新获取文件中的数据
    this->initVector();
    pause();
}

//检测重复
bool Manager::checkRepeat(int id, int type) {
    if(type==1){
        for(vector<Student>::iterator it=vStu.begin();it!=vStu.end();it++){
            if(id == it->m_Id){
                return true;
            }
        }
    }else{
        for(vector<Teacher>::iterator it=vTea.begin();it!=vTea.end();it++){
            if(id == it->m_EmpId){
                return true;
            }
        }
    }
    return false;
}

void printStudent(Student &s){
    cout << "学号: " << s.m_Id << " 姓名： " << s.m_Name << " 密码： " << s.m_Pwd << endl;
}

void printTeacher(Teacher &t){
    cout << "职工号: " << t.m_EmpId << " 姓名： " << t.m_Name << " 密码： " << t.m_Pwd << endl;
}

//查看账号
void Manager::showPerson(){
    cout << "请选择查看内容： " << endl;
    cout << "1、查看所有学生" << endl;
    cout << "2、查看所有老师" << endl;
    int select = 0;
    cin >> select;
    if(select == 1){
        //查看学生
        cout << "所有学生信息如下： " << endl;
        for_each(vStu.begin(), vStu.end(), printStudent);
    }else{
        //查看老师
        cout << "所有老师信息如下： " << endl;
        for_each(vTea.begin(), vTea.end(), printTeacher);
    }
    pause();
}
//查看机房信息
void Manager::showComputer(){
    cout << "机房信息如下： " << endl;
    for (vector<ComputerRoom>::iterator it=vCom.begin();it!=vCom.end();it++){
        cout << "机房编号： " << it->m_ComId << " 机房最大容量: " << it->m_MaxNum << endl;
    }
    pause();
}
//清空预约记录
void Manager::cleanFile(){
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();
    cout << "清空成功！" << endl;
    pause();
}
