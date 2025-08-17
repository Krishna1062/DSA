// https://leetcode.com/problems/design-linked-list/

#include<iostream>
using namespace std;

class Node{
public:
int data;
Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index >= size || index < 0 ){
            return -1;
        }

        Node* curr = head;
        for(int i=0; i<index; i++){
            curr = curr -> next;
        }
        return curr-> data;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode -> next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
        }
        else{
        Node* tail = head;
        while(tail -> next != NULL){
            tail = tail-> next;
        }
        tail->next = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size){
            return;
        }
        if(index == 0){
            addAtHead(val);
            return;
        }
        if(index == size){
            addAtTail(val);
            return;
        }
        Node* curr = head;
        for(int i=0; i<index-1; i++){
            curr = curr-> next;
        }
        Node* newNode = new Node(val);
        newNode -> next = curr->next;
        curr -> next = newNode;
        size++;
        
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size){
            return;
        }
        if(index == 0){
            Node* temp = head;
            head = temp->next;
            delete temp;
            size--;
            return;
        }

        Node* prev = head;
        for(int i=0; i<index-1; i++){
            prev = prev->next;
        }
        Node* nodeToDel = prev->next;
        prev -> next = nodeToDel -> next;
        size--;
        delete nodeToDel;
    }

    void printList() {
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};



int main(){
    int arr[] = {3,4,5,6,7,9};
    MyLinkedList list;
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        list.addAtTail(arr[i]);
    }
    list.printList();
    
    list.addAtHead(7);
    list.printList();
    
    list.addAtIndex(4, 10);
    list.printList();
    
    list.deleteAtIndex(4);
    list.printList();
    return 0;
}