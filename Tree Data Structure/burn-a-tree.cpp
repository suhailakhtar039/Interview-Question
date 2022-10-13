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
int fun(TreeNode* root, int &res, int B){
if(!root) return 0;
if(root->left==NULL && root->right==NULL && root->val==B) return (10000000);
int l=fun(root->left, res, B);
int r=fun(root->right, res, B);
int temp=1+ max(l, r);
int ans=max(temp, l+r+1);
res= max(ans, res);
return temp;
}
int solve(TreeNode* A, int B) {
int res=0;
fun(A, res, B);
return res-10000000;
}
int main(){

}