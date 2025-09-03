//https://leetcode.com/problems/odd-even-linked-list/description/

#include<iostream>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;

    ListNode(int data){
        val = data;
        next = NULL;
    }

};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head -> next == NULL) return NULL;
    ListNode* fast = head;
    ListNode* slow = head;
    
    // take fast n node forward
    for(int i=0; i<n; i++){
        fast = fast -> next;
    }

    if(fast == NULL){
        ListNode* newNode = head -> next;
        delete head;
        return newNode;
    }

    // take slow forward while fast is not on last node
    while(fast && fast -> next != NULL){
        fast = fast -> next;
        slow = slow -> next;
    }

    ListNode* toDelete = slow -> next;
    slow -> next = slow->next->next;
    delete toDelete;
    return head;
}

void printList(ListNode* head){
    while(head != NULL){
        cout<<head->val<<" ";
        head = head -> next;
    }
    cout<<endl;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;

    printList(head);
    head = removeNthFromEnd(head, 3);
    printList(head);
    

}