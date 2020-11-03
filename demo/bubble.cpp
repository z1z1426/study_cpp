//
// Created by ge on 2020/10/28.
//
#include<iostream>
using namespace std;

void bubble(int *arr, int length){
    for(int i=0;i<length;i++){
        for(int j=0;j<length-i-1;j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {4,3,6,9,1,2,10,8,7,5};
    bubble(arr, sizeof(arr)/sizeof(arr[0]));
    for(int i : arr){
        cout << i << " " ;
    }
    return 0;
}