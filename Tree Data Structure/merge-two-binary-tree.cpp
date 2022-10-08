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
TreeNode* solve(TreeNode* root1,TreeNode* root2){
    if(!root1 && !root2){
        return NULL;
    }else if(!root1 && root2){
        return root2;
    }else if(root1 && !root2){
        return root1;
    }

    int val = root1->val+root2->val;
    TreeNode *node = new TreeNode(val);
    node->left = solve(root1->left,root2->left);
    node->right = solve(root1->right,root2->right);
    return node;
}
int main(){
    TreeNode* root1 = createTree();
    TreeNode* root2 = createTree();
    TreeNode* head = solve(root1,root2);
    preorder(head);
}