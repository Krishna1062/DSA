#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    
    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

void inOrder(Node* root){
    if(root == NULL) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    vector<int> arr = {3,5,4,2,6,7,5,8};
    Node* root = NULL;

    for(int x: arr){
        root = insert(root, x);
    }

    inOrder(root);

    return 0;

}