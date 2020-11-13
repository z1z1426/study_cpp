#include <iostream>
#include "teacher.h"
using namespace std;

Teacher::Teacher(){

}

Teacher::Teacher(int empId, string name, string pwd){
    this->m_EmpId = empId;
    this->m_Name = name;
    this->m_Pwd = pwd;
}
//菜单界面
void Teacher::operMenu(){
    cout << "欢迎教师： " << this->m_Name << "登录！" << endl;
    cout << "\t\t ----------------------------------------------------------\n";
    cout << "\t\t|                                                          |\n";
    cout << "\t\t|                      1、查看所有预约                        |\n";
    cout << "\t\t|                                                          |\n";
    cout << "\t\t|                      2、审核预约                           |\n";
    cout << "\t\t|                                                          |\n";
    cout << "\t\t|                      0、注销登录                           |\n";
    cout << "\t\t|                                                          |\n";
    cout << "\t\t ----------------------------------------------------------\n";
    cout << "请选择您的操作: " << endl;
}

//教师菜单
void TeacherMenu(Identity * &teacher){
    while(true){
        //教师菜单
        teacher->operMenu();
        Teacher* tea = (Teacher*)teacher;
        int select = 0;
        cin >> select;
        if(select == 1){
            //查看所有预约
            tea->showAllOrder();
        }else if(select==2){
            //审核预约
            tea->validOrder();
        }else{
            delete teacher;
            cout << "注销成功" << endl;
            pause();
            return;
        }
    }
}

//查看所有预约
void Teacher::showAllOrder(){
    OrderFile of;
    if(of.m_Size == 0){
        cout << "无预约记录" << endl;
        pause();
        return;
    }
    for (int i = 0; i < of.m_Size; ++i) {
        cout << i + 1 << "、 ";
        cout << "预约日期： 周" << of.m_orderData[i]["date"];
        cout << " 时段： " << (of.m_orderData[i]["interval"]=="1"?"上午":"下午");
        cout << " 学号： " << (of.m_orderData[i]["stuId"]);
        cout << " 姓名： " << (of.m_orderData[i]["stuName"]);
        cout << " 机房： " << of.m_orderData[i]["roomId"];
        string status = " 状态： "; //0 取消预约 1 审核中 2 已预约 -1 预约失败
        if (of.m_orderData[i]["status"] == "1"){
            status += "审核中";
        }else if (of.m_orderData[i]["status"]=="2"){
            status += "预约成功";
        }else if(of.m_orderData[i]["status"]=="-1"){
            status += "审核未通过，预约失败";
        }else{
            status += "预约已取消";
        }
        cout << status << endl;
    }
    pause();
}
//审核预约
void Teacher::validOrder(){
    OrderFile of;
    if (of.m_Size == 0) {
        cout << "无预约记录" << endl;
        pause();
        return;
    }
    cout << "待审核的预约记录如下： " << endl;
    vector<int> v;//存放在最大容器中的下标编号
    int index = 1;
    for (int i = 0; i < of.m_Size; i++) {
        //先判断是否为自身学号
        if (of.m_orderData[i]["status"] == "1") {
            v.push_back(i);
            cout << index++ << "、 ";
            cout << "预约日期： 周" << of.m_orderData[i]["date"];
            cout << " 学号： " << (of.m_orderData[i]["stuId"]);
            cout << " 姓名： " << (of.m_orderData[i]["stuName"]);
            cout << " 时段： " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
            cout << " 机房： " << of.m_orderData[i]["roomId"];
            string status = " 状态： 审核中";
            cout << status << endl;
        }
    }
    cout << "请输入审核的记录，0代表返回" << endl;
    int select = 0;
    while(true){
        cin >> select;
        if(select >= 0 && select <= v.size()){
            if(select==0){
                break;
            } else{
                int select1 = 0;
                cout << "1.审核通过" << endl;
                cout << "2.审核不通过" << endl;
                cout << "请输入操作, 0代表返回：" << endl;
                cin >> select1;
                if(select1==0){
                    break;
                } else if(select1==1){
                    //通过情况
                    of.m_orderData[v[select-1]]["status"] = "2";
                }else{
                    //不通过情况
                    of.m_orderData[v[select-1]]["status"] = "-1";
                }
                of.updateOrder();
                cout << "审核完毕" << endl;
                break;
            }
        }
        cout << "输入有误，请重新输入" << endl;
    }
    pause();
}