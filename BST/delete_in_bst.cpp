//https://leetcode.com/problems/delete-node-in-a-bst/description/
#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            data = d;
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

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right); 
}

Node* buildBST(vector<int> &arr){
    Node * root = NULL;

    for(int x:arr){
        root = insert(root, x);
    }
    return root;
}

Node* getInorderSuccessor(Node* root){
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root, int data){
    if(root == NULL){
         return NULL;
    }

    if(data < root->data){
        root->left = delNode(root->left, data);
    }
    else if(data > root->data){
        root -> right = delNode(root->right, data);
    }
    else{// data = root->data
        if(root -> left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        else{// two children node
            Node* insucc = getInorderSuccessor(root->right);
            root -> data = insucc->data;
            root -> right = delNode(root->right, insucc -> data);
        }
    }
    return root;
}

int main(){
    vector<int> arr = {5,4,6,3,7,9,8};
    Node* root = buildBST(arr);
    cout<<"before deleting"<< endl;
    inorder(root);
    cout<<endl;
    cout<<"after deleting"<<endl;
    root = delNode(root, 6);
    inorder(root);


}