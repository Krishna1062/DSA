#include<iostream>
using namespace std;

class stack{
    int t;
    int *arr;
    int cap;
    public:
    stack(int capacity){
        t = -1;
        cap = capacity;
        arr = new int[capacity];
    }
    ~stack(){
        delete[] arr;
    }
    void push(int d){
        if(t >= cap-1) {
            cout<<"Stack overflow"<<endl;
            return;
        }
        t = t+1;
        arr[t] = d;
    }
    void pop(){
        if(t < 0) {
            cout<<"Stack underflow"<<endl;
            return;
        }
        t = t-1;
    }
    int top(){
        if(t<0) {
            return -1;
        }
        return arr[t];
    }
};

int main(){
    stack s(10);
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(6);
    cout<<s.top()<<" ";

    s.pop();
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";

    return 0;

} 