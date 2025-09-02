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
    int lengthOfLoop(Node *head) {
        if(head -> next == NULL){
            return 0;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow -> next;
            fast = fast -> next ->next;
            if(slow == fast) break;
        }
        if(fast == NULL || fast -> next == NULL) return 0;
        
        slow = slow->next;
        int ans = 1;
        while(slow != fast){
            slow = slow -> next;
            ans++;
        }
        return ans;
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
    d->next = b;

    int ans = head->lengthOfLoop(head);
    cout<<ans;
}

