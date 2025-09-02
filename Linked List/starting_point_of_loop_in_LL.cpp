//https://leetcode.com/problems/linked-list-cycle-ii/

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
    Node *detectCycle(Node *head) {
        if(head == NULL || head -> next == NULL) return NULL;
        
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL){
            slow = slow -> next;
            fast = fast -> next;
            if(fast) fast = fast -> next;

            if(fast == slow) break;
        }
        if(fast == NULL) return NULL;
        slow = head;
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return fast;  
    }
};

int main(){
    Node* head = new Node(10);
    Node* a = new Node(9);
    Node* b = new Node(3);
    Node* c = new Node(6);
    Node* d = new Node(4);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = c;

    Node* ans = head->detectCycle(head);
    cout<<ans->data;
}

