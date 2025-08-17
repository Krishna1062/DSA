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

void printList(Node* head) {
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getCount(Node* head) {
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

int main(){
    Node* node1 = new Node(5);
    Node* node2 = new Node(8);
    Node* node3 = new Node(9);
    Node* node4 = new Node(1);

    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;

    cout<<"The length of the list is "<<getCount(node1);
    return 0;
}