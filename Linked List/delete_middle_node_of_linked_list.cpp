// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

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

ListNode* deleteMiddle(ListNode* head) {
    if(head == NULL || head -> next == NULL) return NULL;

    ListNode* fast = head->next->next;
    ListNode* slow = head;

    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    ListNode* temp = slow -> next;
    slow -> next = slow -> next ->next;
    delete temp;;
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
    head = deleteMiddle(head);
    printList(head);
    

}