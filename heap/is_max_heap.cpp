#include<iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    for(int i=0; i<n; i++){
        int leftChild = 2*i+1;
        int rightChild = 2*i+2;
        if(leftChild < n && arr[leftChild] > arr[i]) return false;
        if(rightChild < n && arr[rightChild] > arr[i]) return false;
    }
    return true;
}

int main(){
    int arr[] = {90, 15, 10, 7, 12, 2};
    int n = sizeof(arr)/sizeof(int);
    isMaxHeap(arr, n) ? cout<<"yes":cout<<"no";
    return 0;
}