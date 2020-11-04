#include <iostream>
#include "workerManager.h"
using namespace std;

WorkerManager::WorkerManager() {
    //初始化属性
    //1、文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in); //读文件
    if (!ifs.is_open()){
        cout << "文件不存在" << endl;
        //初始化属性
        //初始化记录人数
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    //2、文件存在 数据为空
    char ch;
    ifs >> ch;
    if (ifs.eof()){
        //文件为空
        cout << "文件为空!" << endl;
        //初始化记录人数
        this->m_EmpNum = 0;
        //初始化数组指针
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    //3、文件存在，并且记录数据
    int num = this->get_EmpNum();
    cout << "职工人数为： " << num << endl;
    this->m_FileIsEmpty = false;
    this->m_EmpNum = num;
    //开辟空间
    this->m_EmpArray = new Worker*[this->m_EmpNum];
    //将文件中的数据，存到数组中
    this->init_Emp();
    //测试代码
    /*for(int i=0;i<this->m_EmpNum;i++){
        cout << "职工编号： " << this->m_EmpArray[i]->m_Id
             << " 姓名： " << this->m_EmpArray[i]->m_Name
             << " 部门编号： " << this->m_EmpArray[i]->m_DeptId << endl;
    }*/
}

//初始化员工
void WorkerManager::init_Emp(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId){
        Worker *worker = NULL;
        if (dId == 1){
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2){
            worker = new Manager(id, name, dId);
        }
        else{
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index++] = worker;
    }
}

void WorkerManager::Show_Menu(){
    cout << "***************************" << endl;
    cout << "******欢迎使用职工管理系统*****" << endl;
    cout << "*******0.退出管理程序********" << endl;
    cout << "*******1.增加职工信息********" << endl;
    cout << "*******2.显示职工信息********" << endl;
    cout << "*******3.删除离职职工********" << endl;
    cout << "*******4.修改职工信息********" << endl;
    cout << "*******5.查找职工信息********" << endl;
    cout << "*******6.按照编号排序********" << endl;
    cout << "*******7.清空所有文档********" << endl;
    cout << "***************************" << endl;
    cout << endl;
}
//退出系统
void WorkerManager::ExitSystem(){
    cout << "欢迎下次使用" << endl;
    exit(0);
}
//添加职工
void WorkerManager::Add_Emp() {
    cout << "请输入加入职工数量" << endl;
    int addNum = 0;//保存用户的输入数量
    cin >> addNum;
    if (addNum <= 0){
        cout << "输入有误" << endl;
    }
    else{
        //添加
        //计算添加新空间大小
        int newSize = this->m_EmpNum + addNum; //新空间大小=原来记录人数+新增人数
        //开辟新空间
        Worker **newSpace = new Worker *[newSize];
        //将原来空间下数据拷贝到新空间下
        if(this->m_EmpArray!=NULL){
            for(int i=0;i<this->m_EmpNum;i++){
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        //批量添加新数据
        for (int i=0; i<addNum; i++){
            int id;//职工编号
            string name;
            int dSelect;
            int flag = 1;
            while (flag) {
                cout << "请输入第" << i + 1 << "个新职工编号: " << endl;
                cin >> id;
                int res = this->IsExist(id);
                if (res==-1){
                    flag = 0;
                }
                else{
                    cout << "该职工编号已存在，请重新输入！" << endl;
                }
            }
            cout << "请输入第" << i+1 << "个新职工姓名: " << endl;
            cin >> name;
            cout << "请选择该职工岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cout << "请输入第" << i+1 << "个新职工岗位编号: " << endl;
            cin >> dSelect;
            Worker *worker = NULL;
            switch (dSelect) {
                case 1:
                    worker = new Employee(id, name, 1);
                    break;
                case 2:
                    worker = new Manager(id, name, 2);
                    break;
                case 3:
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
            }
            newSpace[this->m_EmpNum+i] = worker;
        }
        //释放原有空间
        delete[] this->m_EmpArray;
        //更改新空间的指向
        this->m_EmpArray = newSpace;
        //更新新的职工人数
        this->m_EmpNum = newSize;
        //更新职工不为空标志
        this->m_FileIsEmpty = false;
        //提示添加成功
        cout << "成功添加" << addNum << "名新职工" << endl;
        //成功添加后，保存到文件中
        this->save();
    }
}

void WorkerManager::save(){
    ofstream ofs;
    ofs.open(FILENAME, ios::out); //用输出的方式打开文件 --写文件
    //将每个人数据写入到文件中
    for (int i=0;i<this->m_EmpNum;i++){
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    //关闭文件
    ofs.close();
}

//统计文件中人数
int WorkerManager::get_EmpNum(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in); //打开文件，读方式
    int id;
    string name;
    int dId;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dId){
        //统计人数变量
        num++;
    }
    return num;
}

//显示职工
void WorkerManager::Show_Emp(){
    if (this->m_FileIsEmpty){
        cout << "文件不存在或记录为空！" << endl;
    }
    else{
        for (int i=0;i<m_EmpNum;i++){
            this->m_EmpArray[i]->showInfo();
        }
    }
    //按任意键清屏,windows有效
    //system("pause");
    //system("cls");
}

//删除职工
void WorkerManager::Del_Emp(){
    Show_Emp();
    int id = -1;
    cout << "请输入想要删除的职工编号： " << endl;
    cin >> id;
    int res = IsExist(id);
    if (res != -1){ //说明职工存在，并且要删除掉index位置上的职工
        //数据前移
        for (int i=res;i<this->m_EmpNum-1;i++){
            this->m_EmpArray[i] = this->m_EmpArray[i+1];
        }
        this->m_EmpNum--;//更新数组中记录的人员个数
        //数据同步更新到文件中
        this->save();
        cout << "删除成功" << endl;
    }
    else{
        cout << "该职工编号不存在，请重新输入！" << endl;
    }
}

//判断职工是否存在
int WorkerManager::IsExist(int id){
    int index = -1;
    for (int i=0;i<this->m_EmpNum;i++){
        if (this->m_EmpArray[i]->m_Id == id){
            index = i;
            break;
        }
    }
    return index;
}

//修改职工
void WorkerManager::Mod_Emp() {
    if (this->m_FileIsEmpty){
        cout << "文件不存在或记录为空！" << endl;
    }
    else{
        cout << "请输入修改职工的编号：" << endl;
        int id;
        cin >> id;
        int ret = this->IsExist(id);
        if (ret != -1){
            //查找到编号的职工
            delete this->m_EmpArray[ret];
            int newId = 0;
            string newName = "";
            int dSelect = 0;
            cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
            cin >> newId;
            cout << "请输入新姓名： " << endl;
            cin >> newName;
            cout << "请输入岗位" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;
            Worker *worker = NULL;
            switch (dSelect) {
                case 1:
                    worker = new Employee(newId, newName, 1);
                    break;
                case 2:
                    worker = new Manager(newId, newName, 2);
                    break;
                case 3:
                    worker = new Boss(newId, newName, 3);
                    break;
                default:
                    break;
            }
            //更改数据到数组中
            this->m_EmpArray[ret] = worker;
            cout << "修改成功" << endl;
            //保存到文件中
            this->save();
        }
        else{
            cout << "修改失败，查无此人" << endl;
        }
    }
}

void WorkerManager::Find_Emp(){
    if (this->m_FileIsEmpty){
        cout << "文件不存在或记录为空" << endl;
    }
    else{
        cout << "请输入查找的方式: " << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按姓名查找" << endl;
        int select = 0;
        cin >> select;
        if (select == 1){//按职工号查找
            int id;
            cout << "请输入查找的职工编号: " << endl;
            cin >> id;
            int ret = IsExist(id);
            if (ret != -1){
                //找到职工
                cout << "查找成功！该职工信息如下： " << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else{
                cout << "查找失败，查无此人" << endl;
            }
        }
        else if (select == 2){//按姓名查找
            string name;
            cout << "请输入查找的姓名: " << endl;
            cin >> name;
            bool flag = false; //查找到的标志，默认未找到职工
            for (int i=0;i<m_EmpNum;i++){
                if (m_EmpArray[i]->m_Name == name){
                    cout << "查找成功，职工编号为： "
                         << m_EmpArray[i]->m_Id
                         << " 号的信息如下： " << endl;
                    flag = true;
                    this->m_EmpArray[i]->showInfo();
                }
            }
            if (!flag){
                cout << "查找失败，查无此人" << endl;
            }
        }
        else{
            cout << "输入选项有误" << endl;
        }
    }
}

//按照编号排序
void WorkerManager::Sort_Emp(){
    if (this->m_FileIsEmpty){
        cout << "文件不存在或记录为空！" << endl;
    }
    else{
        cout << "请选择排序方式： " << endl;
        cout << "1、按职工号进行升序" << endl;
        cout << "2、按职工号进行降序" << endl;
        int select = 0;
        cin >> select;
        if (select != 1 && select != 2){
            cout << "输入有误，无法执行" << endl;
        }
        else{
            for (int i=0;i<m_EmpNum;i++){
                int minOrMax = i;
                for (int j = i+1;j<this->m_EmpNum;j++){
                    if (select == 1){//升序
                        if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id){
                            minOrMax = j;
                        }
                    }
                    else{//降序
                        if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id){
                            minOrMax = j;
                        }
                    }
                }
            //判断一开始认定最小值或最大值是不是计算的最小值或最大值，如果不是，交换数据
                if (i!=minOrMax){
                    Worker *temp = this->m_EmpArray[i];
                    this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
                    this->m_EmpArray[minOrMax] = temp;
                }
            }
            cout << "排序成功！排序后的结果为： " << endl;
            this->save(); //排序后结果保存到文件中
            this->Show_Emp();
        }
    }
}

//清空文件
void WorkerManager::Clean_File(){
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;
    int select = 0;
    cin >> select;
    if (select == 1){
        //打开模式ios::trunc如果存在删除文件并重新构建
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();
        if (this->m_EmpArray != NULL){
            //删除堆区的每个职工对象
            for (int i=0;i<this->m_EmpNum;i++){
                if (this->m_EmpArray[i] != NULL){
                    delete this->m_EmpArray[i];
                    this->m_EmpArray[i] = NULL;
                }
            }
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;
        }
        cout << "清空成功！" << endl;
    }
}

WorkerManager::~WorkerManager() {

}
//
//int main() {
//    return 0;
//}
