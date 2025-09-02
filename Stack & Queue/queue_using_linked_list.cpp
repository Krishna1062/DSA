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

class MyQueue{
    Node* start;
    Node* end;
    public:
    MyQueue(){
        start = NULL;
        end = NULL;
    }  

    void push(int val){
        Node* newNode = new Node(val);
        if(end != NULL){
            end -> next = newNode;
        }
        end = newNode;  
        if(start == NULL){
            start = newNode;
        }      
    }

    void pop(){
        if(start == NULL) {
          cout<<"queue is empty";  
        } 
        else{
            Node* temp = start;
            start = start -> next;
            if(start == NULL) end = NULL;
            delete temp;
        }
    }

    int front(){
        if(start == NULL) return -1;
        return start -> data;
    }
};

int main(){
    MyQueue q;
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(0);
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";

}