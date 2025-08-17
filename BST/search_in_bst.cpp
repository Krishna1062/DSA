//https://leetcode.com/problems/search-in-a-binary-search-tree/description/
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
        root -> left = insert(root->left, val);
    }
    else{
        root -> right = insert(root -> right, val);
    }
    return root;
}

Node* BuildBst(vector<int> &arr){
    Node* root = NULL;
    for(int x: arr){
        root = insert(root, x);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* searchBST(Node* root, int key){
    if(root == NULL){
        return NULL;
    }

    if(key == root->data) return root;
    else if(key < root ->data) return searchBST(root->left, key);
    else return searchBST(root->right, key);
}

int main(){
    vector<int> arr = {4,3,5,7,9,1,2};
    Node* root = BuildBst(arr);
    inorder(root);
    cout<<endl;
    Node* search = searchBST(root, 5);
    if(search)
        cout<<1;
    else{
        cout<<0;
    }
    cout<<endl;

}