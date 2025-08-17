#include<iostream>
#include<vector>
using namespace std;

int maxSubArr(vector<int> &nums){
    int sum =0;
    int maxi = nums[0];

    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        maxi = max(maxi, sum);

        if(sum < 0)
            sum = 0;
    }
    return maxi;
}

int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<"The maximum subarray sum is "<<maxSubArr(arr)<<endl;
    return 0;
}