// https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<int> &arr) {
    // Step1: reverse entire array
    reverse(arr.begin(), arr.end());
    
    // Step2: reverse array fron 2nd element to last
    reverse(arr.begin()+1, arr.end());
}
int main(){
    vector<int>arr = {1,2,3,4,5,6,7};
    cout<<"before rotating"<<endl;
    for(int x:arr) cout<<x<<" ";
    cout<<endl;

    rotate(arr);
    cout<<"after rotating"<<endl;
    for(int x:arr) cout<<x<<" ";
    cout<<endl;


    return 0;
}

//https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1