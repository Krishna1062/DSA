#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
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

int findMax(Node *root) {
    if(root == NULL) return -1;
    while(root->right){
        root = root->right;
    }
    return root->data;
}

int findMin(Node *root) {
    if(root == NULL) return -1;
    while(root->left){
        root = root-> left;
    }
    return root->data;
}

int main(){
    vector<int> arr = {3,5,4,2,6,7,5,8};
    Node* root = NULL;

    for(int x: arr){
        root = insert(root, x);
    }

    int minimum = findMin(root);
    int maxi = findMax(root);
    cout<<"Minimum :"<<minimum<<endl<<"Maximum :"<<maxi<<endl;
    
}