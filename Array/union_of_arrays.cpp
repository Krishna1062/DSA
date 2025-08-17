//https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

vector<int> findUnion(vector<int>& a, vector<int>& b) {
    // unordered_map<int, int> freq; // if you don't want output to be sorted
    map<int, int> freq; // if you want output to be sorted
    for(int x: a){
        freq[x]++;
    }
    for(int x: b){
        freq[x]++;
    }
    
    vector<int> uni;
    for(auto &p: freq){
        uni.push_back(p.first);
    }
    
    return uni;
}

void printArr(vector<int>&arr){
    for(int num: arr){
        cout<<num<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr1 = {1,2,2,3,3,4,4};
    vector<int> arr2 = {2,2,3,3,3};

    vector<int> ans= findUnion(arr1, arr2);
    printArr(ans);
    return 0;
}