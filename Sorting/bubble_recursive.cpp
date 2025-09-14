#include<iostream>
using namespace std;

void bubblePass(int *arr, int n, int i){
    if(i==n-1) return ;
    
    if(arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
    
    bubblePass(arr, n, i+1);
    
}
void bubbleSortRecursive(int *arr, int n){
    if(n==1) return ;
    
    bubblePass(arr, n, 0);
    
    bubbleSortRecursive(arr, n-1);
}
void bubbleSort(int *arr, int n) {
    bubbleSortRecursive(arr, n);
}

int main(){
    int arr[] = {8,9,7,6,0,4,5,3};
    int n = sizeof(arr)/sizeof(int);
    bubbleSort(arr, n);
    for(int i=0; i<8; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}