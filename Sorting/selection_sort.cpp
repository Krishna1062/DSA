#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> &arr) {
    for(int i=0; i<arr.size()-1; i++){
        int minIndex = i;
        for(int j=i+1; j<arr.size(); j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
int main(){
    vector<int>arr = {5,4,6,7,3,1,5};
    cout<<"Before Sorting"<<endl;
    for(int x : arr){
        cout<<x<<" ";
    }
    cout<<endl;
    selectionSort(arr);
    cout<<"After Sorting"<<endl;
    for(int x : arr){
        cout<<x<<" ";
    }
    return 0;
}