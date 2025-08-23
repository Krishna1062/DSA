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

bool searchKey(Node* head, int key) {
    while(head!=NULL){
        if(head->data == key) return true;
        head=head->next;
    }
    return false;
}

int main(){
    Node* head = new Node(5);
    head -> next = new Node(6);
    head -> next -> next = new Node(7);
    head -> next -> next -> next = new Node(8);

    searchKey(head, 7)?cout<<"true":cout<<"false";
}