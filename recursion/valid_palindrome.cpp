#include<iostream>
#include<string>
using namespace std;

bool solve(string &s, int start, int end){
    if(start >= end) return true;

    if(!isalnum(s[start])){
        return solve(s, start+1, end);
    }
    if(!isalnum(s[end])){
        return solve(s, start, end-1);
    }

    if(tolower(s[start]) != tolower(s[end])){
        return false;
    }

    return solve(s, start+1, end-1);
}

int main(){
    string s = "aba";
    cout<< solve(s, 0, s.length()-1);
}