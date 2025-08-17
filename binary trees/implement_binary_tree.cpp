#include<iostream>
#include<queue>
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

Node* buildFromArray(int *arr, int n, int &index){
    if(index >= n || arr[index] ==-1){
        index++;
        return NULL;
    }
    Node* root = new Node(arr[index++]);
    root -> left = buildFromArray(arr, n, index);
    root -> right = buildFromArray(arr, n, index);

    return root;
}

Node* buildTree(Node* root){
    int data;
    cout<<"Enter the data :"<<endl;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting to the left of "<<root->data<<endl;
    root -> left = buildTree(root->left);

    cout<<"Enter data for inserting to the right of "<<root->data<<endl;
    root -> right = buildTree(root->right);

    return root;

}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";

            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
    }
}


void inorderTraversal(Node* root){
    if(root== NULL) return ;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preOrder(Node* root){
    if(root == NULL) return ;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL) return ;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


int main(){
    Node* root = NULL;
    int arr[]= {1 ,3 ,4 ,-1, -1, 7, -1,-1, 5, 9, -1, -1 ,-1};
    int n = sizeof(arr)/sizeof(int);
    int index = 0;
    root = buildFromArray(arr, n, index);
    // root = buildTree(root);
    levelOrderTraversal(root);
    cout<<endl;
    inorderTraversal(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
    return 0;
}//1 3 4 -1 -1 7 -1 -1 5 9 -1 -1 -1