#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
       s1.push(x);
    }
    
    int pop() {
        if(empty()) return -1; // empty is not inbuilt it is written below
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ans = s2.top();
        s2.pop();
        return ans;
    }
    
    int peek() {
        if(empty()) return -1;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

 int main(){
    MyQueue q;
    q.push(8);
    q.push(9);
    q.push(10);
    q.push(11);

    cout<<q.pop()<<" ";
    cout<<q.peek()<<" ";
 }