//
// Created by ge on 2020/11/12.
//
#pragma once
#include <iostream>
using namespace std;

//身份抽象类
class Identity{
public:
    //操作菜单
    virtual void operMenu() = 0;
    string m_Name;
    string m_Pwd;
};