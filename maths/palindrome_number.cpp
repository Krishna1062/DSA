#include<iostream>
#include<limits.h>
using namespace std;

bool isPalindrome(int x) {
    if(x<0) return false;
    int cpy = x;
    int rev = 0;
    while(cpy!=0){
        int digit = cpy % 10;
        if(rev < INT_MIN/10 || (rev == INT_MIN/10 && digit < -8)) return false;
        if(rev > INT_MAX/10 || (rev == INT_MAX/10 && digit > 7)) return false;
        rev = rev*10 + digit;
        cpy/=10;
    }
    if(rev == x) return true;
    return false;
}

int main(){
    int n = 151;
    if(isPalindrome(n)) cout<<"True";
    else cout<<"false";
}