#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int>& arr) {
    int n= arr.size();
    for(int i=1; i<n; i++){
        if(arr[i-1] > arr[i]) return false;
    }
    return true;
}
int main(){
    vector<int>arr = {1,2,3,4,5};
    if(isSorted(arr)) cout<<"The array is sorted";
    else cout<<"The array is not sorted";
    return 0;
}

//https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1