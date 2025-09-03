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

ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head -> next == NULL){
        return head;
    }
    ListNode* odd = head;
    ListNode* even = head -> next;
    ListNode* evenStart = even;

    while(even != NULL && even->next != NULL){
        odd -> next = even -> next;
        odd = odd -> next;
        even -> next = odd-> next;
        even = even -> next;
    }
    
    odd -> next = evenStart;
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
    cout<<oddEvenList(head);
    printList(head);
    

}