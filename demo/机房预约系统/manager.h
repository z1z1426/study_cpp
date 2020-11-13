#pragma once
#include <iostream>
#include <vector>
#include "identity.h"
#include "computerRoom.h"

using namespace std;

class Manager: public Identity{
public:
    Manager();
    Manager(string name, string pwd);
    //初始化容器
    void initVector();
    //选择菜单
    virtual void operMenu();
    //添加账号
    void addPerson();
    //查看账号
    void showPerson();
    //查看机房信息
    void showComputer();
    //清空预约记录
    void cleanFile();
    //检测重复 参数：(传入id，传入类型)返回值：(true 代表有重复，false代表没有重复)
    bool checkRepeat(int id, int type);
    //学生账号
    vector<Student>vStu;
    //老师账号
    vector<Teacher>vTea;
    //机房容器
    vector<ComputerRoom> vCom;
};