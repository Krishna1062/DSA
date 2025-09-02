//https://leetcode.com/problems/linked-list-cycle/

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
    bool hasCycle(Node *head) {
        if(head == NULL || head -> next == NULL) return false;
        Node* slow = head;
        Node* fast = head->next;

        while(fast != NULL){
            if(slow == fast) return true;
            slow = slow->next;
            fast = fast -> next;
            if(fast) fast = fast -> next;
        }
        return false;
    }
};

int main(){
    Node* head = new Node(10);
    Node* a = new Node(10);
    Node* b = new Node(10);
    Node* c = new Node(10);
    Node* d = new Node(10);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;

    cout<<head->hasCycle(head);
}

