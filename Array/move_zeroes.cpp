// https://leetcode.com/problems/move-zeroes/description/
#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int> &arr){
    int n = arr.size();
    // nonzero point to first element
    int nonZero = 0;

    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            // if any non zero element if found it is swapped with the arr[nonzero] and nonzero is moved forward as the first non zero element is brought to its correct position
            swap(arr[i], arr[nonZero++]);
        }
    }
}

void printArr(vector<int>&arr){
    for(int num: arr){
        cout<<num<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>arr = {0,1,0,3,12};
    cout<<"Before moving zeroes"<<endl;
    printArr(arr);

    moveZeroes(arr);
    cout<<"After moving zeroes"<<endl;
    printArr(arr);

    return 0;
}