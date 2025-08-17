#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
int main(){
    vector<int>arr = {5,4,6,7,3,1,5};
    cout<<"Before Sorting"<<endl;
    for(int x : arr){
        cout<<x<<" ";
    }
    cout<<endl;
    insertionSort(arr);
    cout<<"After Sorting"<<endl;
    for(int x : arr){
        cout<<x<<" ";
    }
    return 0;
}