// Author : Suhail Akhtar
// Date : 13-10-22
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
// ========
int minDepth(TreeNode *root){
    if(!root)return 0;
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    int l = INT_MAX,r = INT_MAX;
    if(root->left)
        l = minDepth(root->left);
    if(root->right)
        r = minDepth(root->right);
    return 1+min(l,r);
}
int main(){
    TreeNode* root = createTree();
    cout<<minDepth(root);
}