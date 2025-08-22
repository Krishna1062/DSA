#include<iostream>
#include<cmath>
using namespace std;

int countDigits(int n) {
    int count = log10(n) + 1;
    return count;
}

int main(){
    int n = 7798;
    cout<<"The no has "<<countDigits(n)<<" digits";
    return 0;
}