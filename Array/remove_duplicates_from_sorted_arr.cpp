// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int i=0;
    for(int j=1; j<n; j++){
        if(nums[i] != nums[j]){
            i++;
            nums[i] = nums[j];
        }
    }
    return i+1;
}
int main(){
    vector<int>arr = {0,0,1,1,1,2,2,3,3,4};
    cout<<"before removing duplicates"<<endl;
    for(int x:arr) cout<<x<<" ";
    cout<<endl;

    int k = removeDuplicates(arr);
    cout<<"before removing duplicates"<<endl;
    for(int i=0; i<k; i++) cout<<arr[i]<<" ";
    cout<<endl;


    return 0;
}

//https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1