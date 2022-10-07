// Author : Suhail Akhtar
// Date : 07-10-22
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
int height(TreeNode* root){
    if(!root)return 0;
    return 1+max(height(root->left),height(root->right));
}
int solve(TreeNode* root){
    if(!root)return 1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if(abs(leftHeight-rightHeight)>1)return 0;
    return solve(root->left) && solve(root->right);
}
int main(){
    TreeNode* root = createTree();
    cout<<solve(root);
}