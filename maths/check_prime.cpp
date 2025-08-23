#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPrime(int n) {
    int count = 0;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            count++;
            if(n/i != i) count++;
        }
    }
    if(count == 2) return 1;
    return 0;
}

int main(){
    int n = 151;
    cout<<isPrime(n);
}