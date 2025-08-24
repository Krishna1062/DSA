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

vector<vector<int>> zigzagLevelOrder(Node* root) {
    if(root == NULL) return {};

    queue<Node*> q;
    q.push(root);
    vector<vector<int>> ans;
    bool leftToRight = true;

    while(!q.empty()){
        int n = q.size();
        vector<int> level(n);

        for(int i=0; i<n; i++){
            Node* front = q.front();
            q.pop();
            int index = leftToRight? i :(n-i-1);
            level[index] = front->data;
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }            
        ans.push_back(level);
        leftToRight = !leftToRight;
    }
    return ans;
}


int main(){
    Node* root = NULL;
    int arr[]= {3, 9, -1, -1, 20, 15, -1 ,-1, 7, -1, -1};
    int n = sizeof(arr)/sizeof(int);
    int index = 0;
    root = buildFromArray(arr, n, index);
    vector<vector<int>> zigzag = zigzagLevelOrder(root);
    for(int i=0;i<zigzag.size(); i++){
        for(int j=0; j<zigzag[i].size(); j++){
            cout<<zigzag[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}//1 3 4 -1 -1 7 -1 -1 5 9 -1 -1 -1