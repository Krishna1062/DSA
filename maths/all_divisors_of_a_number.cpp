#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_divisors(int n) {
    int num = n;
    vector<int> v;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0) {
            v.push_back(i);
            if(n/i != i) {
                v.push_back(n/i);
            }
        }
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}

int main(){
    int n = 20;
    print_divisors(n);
}