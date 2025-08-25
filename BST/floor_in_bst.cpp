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

int floor(Node* root, int x) {
    int ans = -1;
    while(root){
        if(root->data == x){
            return root->data;
        }
        if(root->data < x){
            ans = root->data;
            root = root->right;
        }
        else{ // root->data > x
            root = root->left;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {3,5,4,2,6,7,5,8};
    Node* root = NULL;

    for(int x: arr){
        root = insert(root, x);
    }

    int ans = floor(root, 6);
    cout<<"Floor :"<<ans<<endl;
    
}