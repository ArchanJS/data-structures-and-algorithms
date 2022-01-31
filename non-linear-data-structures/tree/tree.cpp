#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

//BFS (recursive)
void preOrder(struct Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(struct Node* root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(struct Node* root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

//DFS
void levelWiseTrav(struct Node* root){
    if(root==NULL) return;
    queue<struct Node*> q;
    q.push(root);
    while(!q.empty()){
        int sx=q.size();
        for(int i=0;i<sx;i++){
            struct Node* temp=q.front();
            q.pop();
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
            cout<<temp->data<<" ";
        }
        cout<<endl;
    }
}

//Maximum depth is the no. of nodes from the root node to the farthest leaf node
int maxDepth(struct Node* root){
    if(root==NULL) return 0;
    return 1+max(maxDepth(root->left),maxDepth(root->right));
}

//Balanced if absolute difference between two leaf nodes is <=1
int isBalanced(struct Node* root){
    if(root==NULL) return 0;
    int left=isBalanced(root->left);
    int right=isBalanced(root->right);
    if(left==-1 || right==-1) return -1;
    if(abs(left-right)>1) return -1;
    return max(left,right)+1;
    
}

//The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root
int dia=0;
int diameter(struct Node* root){
    if(root==NULL) return 0;
    int left=diameter(root->left);
    int right=diameter(root->right);
    dia=max(dia,left+right);
    return 1+max(left,right);
}

//Maximum path sum
int mx=INT_MIN;
int maxPathSum(struct Node* root){
    if(root==NULL) return 0;
    int left=maxPathSum(root->left);
    int right=maxPathSum(root->right);
    mx=max(mx,root->data+left+right);
    return root->data+max(left,right);
}

int main(){
    struct Node* root=new Node(-10);
    root->left=new Node(9);
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(7);
    maxPathSum(root);
    cout<<mx;
    return 0;
}