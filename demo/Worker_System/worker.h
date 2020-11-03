//
// Created by ge on 2020/11/3.
//
#pragma once
#include <iostream>
using namespace std;
#ifndef DEMO_WORKER_H
#define DEMO_WORKER_H

#endif //DEMO_WORKER_H

class Worker{
public:
    //显示个人信息
    virtual void showInfo() = 0;
    //获取岗位名称
    virtual string getDeptName() = 0;
    int m_Id;//职工编号
    string m_Name;//职工姓名
    int m_DeptId;//职工部门编号
};