//
// Created by ge on 2020/10/29.
//
#include<iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


struct Hero{
    string h_name;
    int age;
    string sex;
};

void bubbleSort(Hero heros[], int len){
    for (int i=0;i<len;i++){
        for (int j=0;j<len-i-1;j++){
            if (heros[j].age > heros[j+1].age){
                Hero temp = heros[j];
                heros[j] = heros[j+1];
                heros[j+1] = temp;
            }
        }
    }
}

void printHero(Hero heros[], int n){
    for (int i=0;i<n;i++){
        cout << heros[i].h_name << " " << heros[i].age << " " << heros[i].sex << endl;
    }
}

int main(){
    int n;
    cin >> n;
    Hero heros[n];
    for (int i=0;i<n;i++){
        string input;
        int input_1;
        cin >> input;
        heros[i].h_name = input;
        cin >> input_1;
        heros[i].age = input_1;
        cin >> input;
        heros[i].sex = input;
    }
    bubbleSort(heros, n);
    printHero(heros, n);
}