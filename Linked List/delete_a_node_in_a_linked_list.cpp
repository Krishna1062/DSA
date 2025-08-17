//https://leetcode.com/problems/delete-node-in-a-linked-list/
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

void deleteNode(Node* node) {
    node->data=node->next->data;
    node->next=node->next->next;
}
void printList(Node* head) {
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* node1 = new Node(5);
    Node* node2 = new Node(8);
    Node* node3 = new Node(9);
    Node* node4 = new Node(1);

    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    cout<<endl;
    printList(node1);
    deleteNode(node3);
    printList(node1);

}