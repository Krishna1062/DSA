#include<iostream>
using namespace std;

int findSum(int n, int sum) {
    if(n==0) return sum;
    return findSum(n-1, sum+n);
}

int main(){
    cout<<findSum(10, 0);
}