//
// Created by ge on 2020/11/3.
//
#pragma once //防止头文件重复包含
//#ifndef DEMO_WORKERMANAGER_H
//#define DEMO_WORKERMANAGER_H
//
//#endif //DEMO_WORKERMANAGER_H
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

class WorkerManager{
public:
    WorkerManager();
    //展示菜单
    void Show_Menu();
    //退出菜单
    void ExitSystem();
    //记录职工人数
    int m_EmpNum;
    //职工数组指针
    Worker **m_EmpArray;
    //添加职工函数
    void Add_Emp();
    ~WorkerManager();
};