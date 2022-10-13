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
bool find(TreeNode *root,int k){
    if(!root)return false;
    if(root->val==k)return true;
    return find(root->left,k) || find(root->right,k);
}
int lca(TreeNode *root,int a,int b){
    if(root==NULL)return -1;
    if(root->val==a || root->val==b)return root->val;
    int left = lca(root->left,a,b);
    int right = lca(root->right,a,b);
    if(left!=-1 && right!=-1)return root->val;
    return left==-1?right:left;
}
int solve(TreeNode *root,int a,int b){
    if(!find(root,a) || !find(root,b))return -1;
    int ans = lca(root,a,b);
    return ans;
}
int main(){
    TreeNode *root = createTree();
    int a,b;cin>>a>>b;
    cout<<solve(root,a,b);
}