//https://leetcode.com/problems/min-stack/description/

#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    stack<pair<int, int>> s;
    MinStack() {
    }
    
    void push(int val) {
        int currentMin = (s.empty()) ? val : min(val, s.top().second); 
        s.push({val, currentMin});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

int main(){
    MinStack st;
    st.push(-2);
    st.push(0);
    st.push(-3);
    cout<<st.getMin()<<" ";
    st.pop();
    cout<<st.top()<<" ";
    cout<<st.getMin()<<" ";

}