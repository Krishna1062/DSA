// https://www.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1
#include<iostream>
using namespace std;

void heapify(int* arr, int n, int i){
    int largest = i;
    int leftChild = i*2+1;
    int rightChild = i*2+2;

    if(leftChild < n && arr[largest] < arr[leftChild]){
        largest = leftChild;
    }
    if(rightChild < n && arr[largest] < arr[leftChild]){
        largest = rightChild;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void print(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(int);
    
    cout<<"Min heap"<<endl;
    print(arr, n);

    for(int i=(n/2)-1; i>=0; i--){
        heapify(arr, n, i);
    }
    cout<<"Max heap"<<endl;
    print(arr, n);
    return 0;
    
}