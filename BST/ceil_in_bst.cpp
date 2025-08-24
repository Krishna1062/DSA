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

int findCeil(Node* root, int x) {
    if(root == NULL) return -1;
    int ceil = -1;
    while(root){
        if(root->data == x){
            ceil = root->data;
            return ceil;
        }
        
        if(root->data < x){
            root= root->right;
        }
        else{ // root -> data > x
            ceil = root -> data;
            root = root->left;
        }
    }
    return ceil;
}

int main(){
    vector<int> arr = {3,5,4,2,6,7,5,8};
    Node* root = NULL;

    for(int x: arr){
        root = insert(root, x);
    }

    int ceil = findCeil(root, 4);
    cout<<"Ceil :"<<ceil<<endl;
    
}