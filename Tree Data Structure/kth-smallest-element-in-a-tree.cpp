// Author : Suhail Akhtar
// Date : 02-10-22
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
void inorder(TreeNode* root,int k,int &val,int &level){
    if(root==NULL)return;
    inorder(root->left,k,val,level);
    level++;
    if(level==k){
        val = root->val;
        return;
    }
    inorder(root->right,k,val,level);
}
int solve(TreeNode* root,int k){
    int level = 0;
    int val = 0;
    inorder(root,k,val,level);
    return val;
}
int main(){
    TreeNode* root = createTree();
    int k;cin>>k;
    cout<<solve(root,k)<<endl;
}