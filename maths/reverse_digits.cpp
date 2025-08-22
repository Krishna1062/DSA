#include<iostream>
#include<limits.h>
using namespace std;

int reverse(int x) {
    int num = x;
    int ans = 0;
    while(num != 0){
        int digit = num % 10;
        if(ans < INT_MIN/10 || (ans == INT_MIN/10 && digit < -8)) return 0;
        if(ans > INT_MAX/10 || (ans == INT_MAX/10 && digit >7)) return 0;
        num = num / 10;
        ans = ans*10 + digit;
    }
    return ans;
}

int main(){
    int n = 123400;
    int rev = reverse(n);
    cout<<rev;
}