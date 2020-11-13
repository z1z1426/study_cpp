//
// Created by ge on 2020/11/12.
//
#pragma once
#include <iostream>
#include <vector>
#include "identity.h"
#include "computerRoom.h"

using namespace std;

//学生类
class Student: public Identity{
public:
    Student(); //默认构造
    Student(int id, string name, string pwd); //有参构造
    //菜单界面
    virtual void operMenu();
    //申请预约
    void applyOrder();
    //查看我的预约
    void showMyOrder();
    //查看所有预约
    void showAllOrder();
    //取消预约
    void cancelOrder();
    int m_Id;
    //机房容器
    vector<ComputerRoom>vCom;
};