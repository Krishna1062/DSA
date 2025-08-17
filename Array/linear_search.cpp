//https://www.geeksforgeeks.org/problems/search-an-element-in-an-array-1587115621/1
#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& arr, int x) {
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == x) return i;
    }
    return -1;
}
int main(){
    vector<int> arr = {4,5,3,27,8};
    cout<<"Element 27 is present at index "<<search(arr, 27)<<endl;
    return 0;
}