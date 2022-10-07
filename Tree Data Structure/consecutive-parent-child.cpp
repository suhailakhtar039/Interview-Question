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
int solve(TreeNode* root,TreeNode* parent = NULL){
    if(!root)return 0;
    int childVal = root->val;
    if(!parent){
        return solve(root->left,root)+solve(root->right,root);
    }else{
        int parentVal = parent->val;
        int ans = 0;
        if(parentVal==childVal+1 || childVal==parentVal+1){
            ans++;
        }
        ans+=solve(root->left,root);
        ans+=solve(root->right,root);
        return ans;
    }
}
int main(){
    TreeNode* root = createTree();
    cout<<solve(root);
}