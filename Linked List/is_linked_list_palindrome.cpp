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

ListNode* reverse(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* forward = curr->next;

    while(curr!=NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}
bool isPalindrome(ListNode* head) {
    if(head -> next == NULL) return true;

    ListNode* slow = head;
    ListNode* fast = head;
    while(fast -> next != NULL && fast -> next -> next != NULL){
        fast = fast -> next -> next;
        slow = slow ->next;
    }
    ListNode* rev = reverse(slow -> next);
    ListNode* secondHalf = rev;
    ListNode* firstHalf = head;
    bool palindrome = true;
    while(secondHalf != NULL){
        if(secondHalf -> val != firstHalf -> val){
            palindrome = false;
            break;
        }
        secondHalf = secondHalf -> next;
        firstHalf = firstHalf -> next;
    }
    slow->next = reverse(rev);
    return palindrome;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(2);
    ListNode* fourth = new ListNode(1);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    cout<<isPalindrome(head);
    

}