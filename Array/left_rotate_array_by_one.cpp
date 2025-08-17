//https://takeuforward.org/data-structure/left-rotate-the-array-by-one/
#include<iostream>
using namespace std;

void reverseArr(int *arr, int s, int e){
    while(s<=e){
        swap(arr[s++], arr[e--]);
    }
}

//Alternative method
void solve(int *arr, int n){
    int temp = arr[0];

    for(int i=1; i<n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Array before rotating"<<endl;
    for(int num: arr){
        cout<<num<<" ";
    }
    cout<<endl;
    //step 1 reverse the entire array arr - this will take the first element to the last
    // reverseArr(arr, 0, n-1);
    
    //step 2 reverse the array from first element to the second last element
    // reverseArr(arr, 0, n-2);

    //Alternative
    solve(arr, n);

    cout<<"Array after rotating"<<endl;
    for(int num: arr){
        cout<<num<<" ";
    }
    cout<<endl;
}