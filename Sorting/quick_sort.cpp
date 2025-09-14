#include<iostream>
using namespace std;

int partition(int* arr, int low, int high) {
    int count = 0;
    for(int i=low+1; i<=high; i++){
        if(arr[i] <= arr[low]) count++;
    }
    
    int pivotIndex = low + count;
    swap(arr[low], arr[pivotIndex]);
    
    int i = low;
    int j = high;
    
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i] <= arr[pivotIndex]){
            i++;
        }
        while(arr[j] > arr[pivotIndex]){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int* arr, int low, int high) {
    if(low >= high) return;
    
    int pivot = partition(arr, low, high);
    
    quickSort(arr, low, pivot-1);
    
    quickSort(arr, pivot+1, high);
}

int main(){
    int arr[] = {5,6,4,7,8,4,6,2};
    quickSort(arr, 0, 7);
    for(int i=0; i<8; i++){
	cout<<arr[i]<<" ";
    }
    return 0;
}