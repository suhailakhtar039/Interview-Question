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
void lastNode(TreeNode* root,int curLevel,int &mxLevel,int &ans){
    if(!root)return;
    if(curLevel>mxLevel){
        mxLevel = curLevel;
        ans = root->val;
    }
    lastNode(root->right,curLevel+1,mxLevel,ans);
    lastNode(root->left,curLevel+1,mxLevel,ans);
}
int solve(TreeNode* root){
    int level = 1,mxLevel=0,ans=-1;
    lastNode(root,level,mxLevel,ans);
    return ans;
}
int main(){
    TreeNode* root = createTree();
    cout<<solve(root);
}