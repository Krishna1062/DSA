#include<iostream>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size = 0;

    void insert(int val){
        size = size +1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;
            if(arr[index] > arr[parent]){
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else{
                return ;
            }
        }
    }

    void deletex(){
        if(size ==0 ) {
            cout<<"it is empty"<<endl;
            return;
        }
        swap(arr[1], arr[size]);
        size--;
        int index = 1;

        while(index <= size){
            int left = index*2;
            int right = index*2+1;
            int largest = index;
            
            if(left <= size && arr[left] > arr[largest]){
                largest = left;
            }
            if(right <= size && arr[right] > arr[largest]){
                largest = right;
            }
            if(largest != index){
                swap(arr[largest], arr[index]);
                index = largest;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

void heapify(int *arr, int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right<=n && arr[largest] < arr[right]){
        largest = right;
    }
    
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n){
    int size = n;
    while(size > 1){
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main(){
    Heap h;
    h.insert(10);
    h.insert(80);
    h.insert(90);
    h.insert(13);
    h.insert(9);
    
    h.print();
    h.deletex();
    h.print();
    h.print();
    
    
    int arr[] = {-1, 10, 80, 90, 13, 9};
    int n = sizeof(arr)/sizeof(int)-1;
    
    // take n/2 because leaf nodes are already heap so they are not included
    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }
    
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr, n);
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}