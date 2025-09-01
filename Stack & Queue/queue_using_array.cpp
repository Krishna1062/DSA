#include<iostream>
using namespace std;

class Queue{
    int f;
    int cap;
    int *arr;
    int r;
    int size;

    public:
    Queue(int cap){
        this->cap = cap;
        f = 0;
        r = -1;
        arr = new int[cap];
        size = 0;
    }

    ~Queue(){
        delete[] arr;
    }

    void push(int d){
        if(size == cap){
            cout<<"Queue overflow";
            return;
        }
        r = (r+1)%cap;
        arr[r] = d;
        size++;
    }

    void pop(){
        if(size==0){
            cout<<"Queue underflow";
            return ;
        }
        f = (f+1)%cap;
        size--;

        if(size==0){
            f = 0;
            r = -1;
        }
    }

    int front(){
        if(size==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[f];
    }
};

int main(){
    Queue q(5);

    q.push(9);
    q.push(8);
    q.push(7);
    q.push(6);
    q.push(5);
    q.push(5);


    cout<<endl;
    cout<<q.front()<<" ";

    q.pop();
    
    cout<<endl;
    cout<<q.front()<<" ";

    q.pop();
    
    cout<<endl;
    cout<<q.front()<<" ";

    q.pop();
    
    cout<<endl;
    cout<<q.front()<<" ";

    q.pop();
    
    cout<<endl;
    cout<<q.front()<<" ";

    q.pop();
    
    cout<<endl;
    cout<<q.front()<<" ";

}