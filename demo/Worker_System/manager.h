//
// Created by ge on 2020/11/3.
//
#pragma once
#include <iostream>
#include "worker.h"
using namespace std;
#ifndef DEMO_WORKER_H
#define DEMO_WORKER_H

#endif //DEMO_WORKER_H

class Manager: public Worker{
public:
    //构造函数
    Manager(int id, string name, int dId);
    //显示个人信息
    void showInfo();
    //获取岗位名称
    string getDeptName();
};