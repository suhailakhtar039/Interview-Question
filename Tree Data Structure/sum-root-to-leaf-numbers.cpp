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
int mod = 1003;
void allSum(TreeNode *root,int &ans,int temp = 0){
    if(!root)return;
    if(root->left==NULL && root->right==NULL){
        temp = (temp*10%mod+root->val%mod);
        ans = (ans%mod+temp%mod)%mod;
        return;
    }
    temp=(temp*10%mod+root->val%mod)%mod;
    allSum(root->left,ans,temp);
    allSum(root->right,ans,temp);
}
int solve(TreeNode* root){
    int ans = 0;
    allSum(root,ans);
    return ans;
}
int main(){
    TreeNode* root = createTree();
    cout<<solve(root);
}