//
// Created by ge on 2020/11/11.
//

#ifndef DEMO_SPEECHMANAGER_H
#define DEMO_SPEECHMANAGER_H

#endif //DEMO_SPEECHMANAGER_H
#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "player.h"

using namespace std;

//设计演讲管理类
class SpeechManager{
public:
    //构造函数
    SpeechManager();
    //展示菜单
    void show_Menu();
    //退出系统
    void exitSystem();
    //析构函数
    ~SpeechManager();
    //初始化容器和属性
    void initSpeech();
    //创建选手
    void createPlayer();
    //开始比赛
    void startGame();
    //抽签
    void speechDraw();
    //比赛
    void speechContest();
    //显示分数
    void showScore();
    //保存记录
    void saveRecord();
    //读取记录
    void loadRecord();
    //查看记录
    void showRecord();
    //清空记录
    void clearRecord();
    //成员属性
    //保存第一轮比赛选手编号容器
    vector<int>v1;
    //第一轮晋级选手编号容器
    vector<int>v2;
    //胜出前三名选手编号容器
    vector<int>vVictory;
    //存放编号以及对应具体选手容器
    map<int, Player>mPlayer;
    //存放比赛轮数
    int mIndex;
    bool fileIsEmpty; //判断文件是否为空
    map<int, vector<string>>m_Record;
};