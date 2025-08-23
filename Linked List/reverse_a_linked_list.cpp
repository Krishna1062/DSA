// https://leetcode.com/problems/reverse-linked-list/
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

Node* reverseList(Node* head) {
    if(head == NULL) return NULL;
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node*forward = curr->next;
        curr -> next = prev;
        prev = curr;            
        curr = forward;
    }

    return prev;
}

void printList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    Node* head = new Node(5);
    head -> next = new Node(6);
    head -> next -> next = new Node(7);
    head -> next -> next -> next = new Node(8);

    cout<<"before"<<endl;
    printList(head);
    
    head = reverseList(head);

    cout<<"after"<<endl;
    printList(head);
}