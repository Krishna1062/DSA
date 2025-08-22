#include<iostream>
using namespace std;

bool armstrongNumber(int n) {
    int copy = n;
    int arm = 0;
    while(copy != 0){
        int digit = copy%10;
        arm = arm + digit*digit*digit;
        copy /= 10;
    }
    if(arm != n) return false;
    return true;
}

int main(){
    int n = 153;
    if(armstrongNumber(n)) cout<<"True";
    else cout<<false;
}