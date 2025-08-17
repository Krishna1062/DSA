//https://leetcode.com/problems/missing-number/description/
#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    //step 1 find sum of all values in range 0 to n and sum of array;
    int n = nums.size();
    int sum = n*(n+1)/2;
    int arrSum = 0;
    for(int i=0; i<n; i++){
        arrSum += nums[i];
    }

    return sum - arrSum;

}
int main(){
    vector<int> arr = {3,0,1};
    cout<<"Element missing is "<<missingNumber(arr)<<endl;
    return 0;
}