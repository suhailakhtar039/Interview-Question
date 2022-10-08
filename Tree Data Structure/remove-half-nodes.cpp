// Author : Suhail Akhtar
// Date : 08-10-22
#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
TreeNode *createTree(){
    int x;cin>>x;
    if(x==-1)return NULL;
    TreeNode *root = new TreeNode(x);
    cout<<"Enter left child of "<<x<<" (or -1 to stop):";
    root->left = createTree();
    cout<<"Enter right child of "<<x<<" (or -1 to stop):";
    root->right = createTree();
    return root;
}
TreeNode* createBST(TreeNode* root,int val){
    if(root==NULL){
        return new TreeNode(val);
    }
    if(val<root->val)
        root->left = createBST(root->left,val);
    else
        root->right = createBST(root->right,val);
    return root;
}
void preorder(TreeNode* root){
    if(root==NULL)return ;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
TreeNode* solve(TreeNode* root){
    if(!root)return NULL;
    root->left = solve(root->left);
    root->right = solve(root->right);
    if(!root->left && !root->right)return root;
    if(root->left == NULL){
        TreeNode *newNode = root->right;
        return newNode;
    }
    if(root->right == NULL){
        TreeNode *newNode = root->left;
        return newNode;
    }
    return root;
}
int main(){
    TreeNode *root = createTree();
    TreeNode *ans = solve(root);
    preorder(ans);   
}