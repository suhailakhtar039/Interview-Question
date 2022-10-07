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
void inorder(TreeNode* root,int &k,vector<int> temp,vector<int> &ans){
    if(!root)return;
    temp.push_back(root->val);
    if(root->val==k){
        ans = temp;
    }
    inorder(root->left,k,temp,ans);
    inorder(root->right,k,temp,ans);
    temp.pop_back();
}
vector<int> solve(TreeNode* root,int k){
    vector<int> ans,temp;
    inorder(root,k,temp,ans);
    return ans;
}

int main(){
    TreeNode* root = createTree();
    int k;cin>>k;
    vector<int> ans = solve(root,k);
    for(auto it:ans)
        cout<<it<<" ";
}