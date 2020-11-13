#include <iostream>
#include "speechManager.h"
#include "speechManager.cpp"
using namespace std;

int main() {
    //创建管理类对象
    srand((unsigned int)time(NULL));
    SpeechManager sm;
    int choice = 0;//用来存储用户的选项
    int num;
    while(true){
        sm.show_Menu();
        cout << "请输入您的选择： " << endl;
        cin >> choice;
        switch (choice) {
            case 1://开始比赛
                sm.startGame();
                cout << "输入任意数字并回车继续..." << endl;
                cin;
                break;
            case 2://查看往届记录
                sm.showRecord();
                cout << "输入任意数字并回车继续..." << endl;
                cin >> num;
                break;
            case 3://清空比赛记录
                sm.clearRecord();
                break;
            case 0://退出
                sm.exitSystem();
                break;
            default:
                break;
        }
    }

    return 0;
}
