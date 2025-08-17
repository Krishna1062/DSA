#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int getSecondLargest(vector<int> &arr) {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    
    for(int num: arr){
        if(num > largest){
            secondLargest = largest;
            largest = num;
        }
        else if(num > secondLargest && num < largest){
            secondLargest = num;
        }
    }
    return (secondLargest == INT_MIN) ? -1 : secondLargest;
}
int main(){
    vector<int>arr = {5,4,6,7,3,1,5};
    cout<<"The second largest element is :"<<getSecondLargest(arr);
    return 0;
}