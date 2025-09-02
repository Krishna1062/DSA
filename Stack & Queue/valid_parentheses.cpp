//https://leetcode.com/problems/valid-parentheses/

#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(char ch: s){
        if(ch == '{' || ch == '[' || ch == '('){
            st.push(ch);
        }
        else if(!st.empty()){
            if((st.top() == '(' && ch == ')') || (st.top() == '[' && ch == ']') 
            || (st.top() == '{' && ch == '}')) {   
                st.pop();
            }
            else{
                return false;
            }
        }
        else {
            return false;
        }
    }

    if(st.empty())
        return true;
    return false;
}

int main(){
    string s = "{{()}}[]{}";
    cout<<isValid(s);
}