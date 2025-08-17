// https://leetcode.com/problems/rotate-array/description/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    k = k % n;
    // step 1: reverse entire array:
    reverse(nums.begin(), nums.end());

    // step 2: reverse elements from 0 to k
    reverse(nums.begin(), nums.begin()+k);

    // step 3: reverse element front k to end;
    reverse(nums.begin()+k, nums.end());
}
int main(){
    vector<int>arr = {1,2,3,4,5,6,7};
    cout<<"before rotating"<<endl;
    for(int x:arr) cout<<x<<" ";
    cout<<endl;

    rotate(arr, 3);
    cout<<"after rotating"<<endl;
    for(int x:arr) cout<<x<<" ";
    cout<<endl;


    return 0;
}

//https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1