//https://leetcode.com/problems/two-sum/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int,int>> arr;
    for(int i=0; i<nums.size(); i++){
        arr.push_back({nums[i], i});
    }
    sort(arr.begin(), arr.end());

    int s=0; 
    int e=arr.size()-1;
    while(s<e){
        if(arr[s].first + arr[e].first > target){
            e--;
        }
        else if(arr[s].first + arr[e].first < target){
            s++;
        }
        else{
            return {arr[s].second, arr[e].second};
        }
    }

    return {};
}

int main(){
    vector<int> arr = {2,7,-2,-1};
    vector<int> ans = twoSum(arr, 9);
    for(int n:ans){
        cout<<n<<" ";
    }
    cout<<endl;
    return 0;
}