#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class MyStack{
    Node* t;

    public:
    MyStack(){
        t=NULL;
    }
    void push(int val){
        Node* newNode = new Node(val);
        newNode->next = t;
        t = newNode;
    }

    void pop(){
        if(t == NULL) {
            cout<<"Stack underflow";
        }
        else{
            Node* temp = t;
            t = t -> next;
            delete temp;
        }
    }

    int top(){
        if (t == NULL) {
            cout<<"Stack is empty";
            return -1;
        }
        return t->data;
    }
};

int main(){
    MyStack s;
    s.push(10);
    s.push(9);
    s.push(8);
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
}