// Author : Suhail Akhtar
// Date : 12-10-22
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
bool pathSum(TreeNode* root,int &sum,int initialSum = 0){
    if(!root)return false;
    if(root->left==NULL && root->right==NULL){
        initialSum+=root->val;
        return sum == initialSum;
    }
    bool lsum = pathSum(root->left,sum,initialSum+root->val);
    bool rsum = pathSum(root->right,sum,initialSum+root->val);
    return lsum || rsum;
}
bool solve(TreeNode* root,int sum){
    return pathSum(root,sum);
}
int main(){
    TreeNode *root = createTree();
    int sum;cin>>sum;
    cout<<solve(root,sum);
}