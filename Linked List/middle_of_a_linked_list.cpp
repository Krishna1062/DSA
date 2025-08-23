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

Node* middleNode(Node* head) {
    Node* fast = head->next;
    Node* slow = head;
    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
    }
    return slow;
}

int main(){
    Node* head = new Node(5);
    head -> next = new Node(6);
    head -> next -> next = new Node(7);
    head -> next -> next -> next = new Node(8);

    Node* middle = middleNode(head);
    cout<<middle->data;
}