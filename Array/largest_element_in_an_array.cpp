#include<iostream>
#include<vector>
using namespace std;

int largest(vector<int> &arr) {
    // code here
    int maxi = arr[0];
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > maxi) maxi = arr[i];
    }
    return maxi;
}
int main(){
    vector<int>arr = {5,4,6,7,3,1,5};
    cout<<"The largest element is :"<<largest(arr);
    return 0;
}