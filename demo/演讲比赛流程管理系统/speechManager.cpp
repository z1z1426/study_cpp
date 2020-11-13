#include <iostream>
#include <algorithm>
#include <deque>
#include "speechManager.h"
#include "player.h"
#include "fstream"
using namespace std;

//构造函数
SpeechManager::SpeechManager(){
    //初始化容器和属性

//    this->initSpeech();
//    //创建选手
//    this->createPlayer();
}

void SpeechManager::show_Menu() {
    cout << "***************************" << endl;
    cout << "*******欢迎参加演讲比赛*******" << endl;
    cout << "*******1、开始演讲比赛********" << endl;
    cout << "*******2、查看往届记录********" << endl;
    cout << "*******3、清空比赛记录********" << endl;
    cout << "*******0、退出比赛程序********" << endl;
    cout << "***************************" << endl;
    cout << endl;
}

//退出系统
void SpeechManager::exitSystem() {
    cout << "欢迎下次使用" << endl;
    exit(0);
}

void SpeechManager::initSpeech() {
    //容器都置空
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->mPlayer.clear();
    this->mIndex = 1;
    this->m_Record.clear();
}

//创建选手
void SpeechManager::createPlayer() {
    string nameSeed = "ABCDEFGHIJKL";
    for (int i=0; i<nameSeed.size();i++){
        string name = "选手";
        Player p;
        name += nameSeed[i];
        p.m_Name = name;
        for (int j=0;j<2;j++){
            p.m_score[j] = 0;
        }
        //12名选手编号
        this->v1.push_back(i+10001);
        //选手编号 以及相应的选手 存放到map容器中
        this->mPlayer.insert(make_pair(i+10001, p));
    }
}

void SpeechManager::speechDraw() {
    cout << "第" << this->mIndex << "轮比赛选手正在抽签" << endl;
    cout << "---------------------------------" << endl;
    cout << "抽签后演讲顺序如下: " << endl;
    if (this->mIndex == 1){
        random_shuffle(v1.begin(), v1.end());
        for(vector<int>::iterator it = v1.begin();it!=v1.end();it++){
            cout << *it << " ";
        }
        cout << endl;
    }
    else{
        random_shuffle(v2.begin(), v2.end());
        for(vector<int>::iterator it = v2.begin();it!=v2.end();it++){
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "---------------------------------" << endl;
}

//比赛
void SpeechManager::speechContest(){
    cout << "-------------第" << this->mIndex << "轮比赛正式开始-----------------" << endl;
    vector<int>vSrc;
    multimap<double, int, greater<double>>groupScore;
    if (this->mIndex==1){
        vSrc = v1;
    }else{
        vSrc = v2;
    }
    int num = 0;
    for (vector<int>::iterator it=vSrc.begin();it!=vSrc.end();it++){
        num++;
        deque<double>d;
        for(int i=0;i<10;i++){
            d.push_back((rand()%401+600)/10.f);
        }
        sort(d.begin(), d.end(), greater<double>());
        d.pop_front();
        d.pop_back();
        double sum = accumulate(d.begin(), d.end(), 0.0f);
        double score = sum / double(d.size());
        this->mPlayer[*it].m_score[this->mIndex-1] = score;
        groupScore.insert(make_pair(score, *it));
        if (num%6==0){
            cout << "第" << num/6 << "小组比赛名次： " << endl;
            for(multimap<double, int>::iterator it1=groupScore.begin();it1!=groupScore.end();it1++){
                cout << "编号： " << it1->second << " 姓名： " << this->mPlayer[it1->second].m_Name <<
                " 成绩： " << it1->first << endl;
            }
            int count = 0;
            for(multimap<double, int>::iterator it1=groupScore.begin();it1!=groupScore.end()&&count<3;it1++, count++){
                if(this->mIndex==1){
                    this->v2.push_back(it1->second);
                }else{
                    this->vVictory.push_back(it1->second);
                }
            }
            groupScore.clear();
            cout << endl;
        }

    }
    cout << "-------------第" << this->mIndex << "轮比赛完毕---------------";
    cout << endl;
}

//显示比赛分数
void SpeechManager::showScore() {
    cout << "------------第" << this->mIndex << "轮晋级选手信息如下：-------------" << endl;
    vector<int>v;
    if(this->mIndex==1){
        v = v2;
    }else{
        v = vVictory;
    }
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){

        cout << "编号： " << *it << " 姓名： " << this->mPlayer[*it].m_Name << " 成绩： "
        << this->mPlayer[*it].m_score[this->mIndex-1] << endl;
    }
}

void SpeechManager::saveRecord() {
    ofstream ofs;
    ofs.open("speech.csv", ios::out|ios::app); //用输出的方式打开文件 --写文件
    //将每个人数据写入到文件中
    for(vector<int>::iterator it=this->vVictory.begin();it!=this->vVictory.end();it++){
        ofs << *it << "," << mPlayer[*it].m_score[1] << ",";
    }
    ofs << endl;
    //关闭文件
    ofs.close();
    cout << "记录已经保存" << endl;
}

void SpeechManager::loadRecord() {
    ifstream ifs;
    ifs.open("speech.csv", ios::in); //输入流对象 读取文件
    if(!ifs.is_open()){
        this->fileIsEmpty = true;
//        cout << "文件不存在！" << endl;
        ifs.close();
        return;
    }
    this->fileIsEmpty = false;
    //文件清空情况
    char ch;
    ifs >> ch;
    if(ifs.eof()){
//        cout << "文件为空！" << endl;
//        this->fileIsEmpty = true;
        ifs.close();
        return;
    }
    //文件不为空
    ifs.putback(ch); //将上面读取的单个字符放回去
    string data;
    int index = 0;
    while (ifs >> data){
        vector<string>v;
        int pos = -1; //查到","位置的变量
        int start = 0;
        while (true){
            pos = data.find(',', start); //从0开始查找','
            if(pos == -1){
                break; //没有找到的情况
            }
            string tmp = data.substr(start, pos-start); //找到了，进行分割 参数1 起始位置， 参数2 截取长度
            v.push_back(tmp);
            start = pos + 1;
        }
        this->m_Record.insert(make_pair(index++, v));
    }
    ifs.close();
}

//查看记录
void SpeechManager::showRecord(){
    this->loadRecord();
    if(this->fileIsEmpty){
        cout << "文件不存在！" << endl;
        return;
    }
    if(!m_Record.size()){
        cout << "记录为空！" << endl;
        return;
    }
    for(int i=0;i<this->m_Record.size();i++){
        cout << "第" << i+1 << "届"
        << "冠军编号： " << this->m_Record[i][0] << " 得分： " << this->m_Record[i][1] << " "
        << "亚军编号： " << this->m_Record[i][2] << " 得分： " << this->m_Record[i][3] << " "
        << "季军编号： " << this->m_Record[i][4] << " 得分： " << this->m_Record[i][5] << " " << endl;
    }
};

//清空记录
void SpeechManager::clearRecord() {
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;
    int select = 0;
    cin >> select;
    if (select == 1){
        //确认清空
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();
        this->initSpeech();
        this->createPlayer();
        this->loadRecord();
        cout << "清空成功!" << endl;
    }
}

//开始比赛
void SpeechManager::startGame() {
    this->initSpeech();
    this->createPlayer();
    //第一轮比赛
    //1、抽签
    this->speechDraw();
    //2、比赛
    this->speechContest();
    //3、显示晋级结果
    this->showScore();
    //第二轮比赛
    this->mIndex++;
    //1、抽签
    this->speechDraw();
    //2、比赛
    this->speechContest();
    //3、显示结果
    this->showScore();
    //保存分数
    this->saveRecord();
    cout << "本届比赛完毕！" << endl;
}

//析构函数
SpeechManager::~SpeechManager(){

}


