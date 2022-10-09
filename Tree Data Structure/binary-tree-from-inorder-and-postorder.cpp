// Author : Suhail Akhtar
// Date : 09-10-22
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
// =========
TreeNode* solve(vector<int> &pre,unordered_map<int,int> &m,int &idx,int lo,int hi){
    if(lo>hi)return NULL;
    int searchIndex = m[pre[idx]];
    TreeNode* node = new TreeNode(pre[idx--]);
    if(lo==hi)return node;
    node->right = solve(pre,m,idx,searchIndex+1,hi);
    node->left = solve(pre,m,idx,lo,searchIndex-1);
    return node;
}
TreeNode* construct(vector<int> &in,vector<int> &post){
    int n = post.size();
    unordered_map<int,int> m;
    for(int i=0; i<n; i++)m[in[i]]=i;
    int lo = 0, hi = n-1, idx = n-1;
    TreeNode* root = solve(post,m,idx,lo,hi);
    return root;
}
int main(){
    int n;cin>>n;
    vector<int> pre(n),in(n);
    for(int i=0; i<n; i++)cin>>pre[i];
    for(int i=0; i<n; i++)cin>>in[i];
    TreeNode* root = construct(pre,in);
    preorder(root);
}