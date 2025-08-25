#include<iostream>
using namespace std;

void solve(int *arr, int s, int e){
    if(s>=e) return;
    swap(arr[s], arr[e]);
    solve(arr, s+1, e-1);
}

int main(){
    int arr[6] = {1,2,3,4,5,6};
    solve(arr, 0, sizeof(arr)/sizeof(int)-1);
    for(int i=0; i < sizeof(arr)/sizeof(int); i++){
        cout<<arr[i]<<" ";
    }
}