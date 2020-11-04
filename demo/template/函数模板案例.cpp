#include <iostream>

using namespace std;

//实现通用 对数组进行排序的函数
//规则 从大到小
//算法 选择
//测试 char数组、int数组

//交换
template<typename T>
void mySwap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

//排序算法
template<typename T>
void mySort(T arr[], int len){
    for (int i=0; i<len-1; i++){
        int max = i;
        for (int j=i+1; j<len; j++){
            if (arr[j] > arr[max]){
                max = j;
            }
        }
        if (i != max){
            mySwap(arr[i], arr[max]);
        }
    }
}

//打印数组模板
template<typename T>
void printArr(T arr[], int len){
    for (int i=0;i<len;i++){
        cout << arr[i] << " ";
    }
}

void test01(){
    //测试char数组
    char charArr[] = "badcfe";
    int num = sizeof(charArr) / sizeof(char);
    mySort(charArr, num);
    printArr(charArr, num);
}

void test02(){
    //测试int数组
    int intArr[] = {7, 5, 1, 3, 9, 2, 4, 6, 8};
    int num = sizeof(intArr) / sizeof(int);
    mySort(intArr, num);
    printArr(intArr, num);
}

int main() {
    test01();
    cout << endl;
    test02();
    return 0;
}
