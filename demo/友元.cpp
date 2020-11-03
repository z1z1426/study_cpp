#include <iostream>

using namespace std;

//建筑物类
//class Building{
//    //goodGay全局函数是Building好朋友，可以访问Building私有成员
//    friend void goodGay(Building *building);
//public:
//    Building(){
//        m_SittingRoom = "客厅";
//        m_BedRoom = "卧室";
//    }
//    string m_SittingRoom;//客厅
//private:
//    string m_BedRoom;//卧室
//};

//class Building{
//    friend class GoodGay;
//public:
//    Building();
//    string m_SittingRoom;//客厅
//private:
//    string m_BedRoom;//卧室
//};
//
////类外写成员函数
//Building::Building(){
//    m_SittingRoom = "客厅";
//    m_BedRoom = "卧室";
//};
//
//class GoodGay{
//public:
//    GoodGay();
//    void visit();//参观函数 访问Building中的属性
//    Building *building;
//};
//
//GoodGay::GoodGay(){
//    //创建建筑物对象
//    building = new Building;
//    //Building *building;
//}
//
//void GoodGay::visit() {
//    cout << "好基友类正在访问:" << building->m_SittingRoom << endl;
//    cout << "好基友类正在访问：" << building->m_BedRoom << endl;
//}

//全局函数
//void goodGay(Building *building){
//    cout << "好基友全局函数 正在访问：" << building->m_SittingRoom << endl;
//    cout << "好基友全局函数 正在访问：" << building->m_BedRoom << endl;
//}

//void test01(){
//    Building building;
////    goodGay(&building);
//}
//
//void test02(){
//    GoodGay gg;
//    gg.visit();
//}
class Building;
class GoodGay{
public:
    GoodGay();
    void visit(); //让visit函数可以访问Building中私有成员
    void visit2(); //让visit2函数不可以访问Building中私有成员
    Building *building;
};
class Building{
    //告诉编译器 GoodGay类下的visit成员函数作为本类的好朋友，可以访问私有成员
    friend void GoodGay::visit();
public:
    Building();
    string m_SittingRoom; //客厅
private:
    string m_BedRoom; //卧室
};
Building::Building(){
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}


GoodGay::GoodGay(){
    building = new Building;
}

void GoodGay::visit() {
    cout << "visit函数正在访问：" << building->m_SittingRoom << endl;
    cout << "visit函数正在访问：" << building->m_BedRoom << endl;
}

void GoodGay::visit2() {
    cout << "visit函数正在访问：" << building->m_SittingRoom << endl;
   // cout << "visit函数正在访问：" << building->m_BedRoom << endl;
}

void test03(){
    GoodGay gg;
    gg.visit();
    gg.visit2();
}

int main() {
    //test01();
    //test02();
    test03();
    return 0;
}
