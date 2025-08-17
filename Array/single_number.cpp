//https://leetcode.com/problems/single-number/
#include<iostream>
#include<vector>
using namespace std;


int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        ans = ans ^ nums[i];
    }
    return ans;
}

void printArr(vector<int>&arr){
    for(int num: arr){
        cout<<num<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr1 = {1,1,2,3,3};
    
    cout<<"Element which occurred single is "<<singleNumber(arr1);
    return 0;
}