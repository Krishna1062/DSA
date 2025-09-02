#include<iostream>
#include<queue>
using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i=0; i<size; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(q.size() == 0) return -1;
        int s = q.front();
        q.pop();
        return s;
    }
    
    int top() {
        if(q.size() == 0) return -1;
        return q.front();
    }
    
    bool empty() {
        if(q.size()==0) return true;
        return false;
    }
};

 int main(){
    MyStack s;
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);

    cout<<s.pop()<<" ";
    cout<<s.top()<<" ";
 }