// Author : Suhail Akhtar
// Date : 10-10-22
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
// ==============
void preorder(TreeNode* root,map<int,int> &m,int dist){
    if(!root)return;
    m[dist]+=root->val;
    preorder(root->left,m,dist-1);
    preorder(root->right,m,dist+1);
}
vector<int> solve(TreeNode* root){
    map<int,int> m;
    vector<int> ans;
    preorder(root,m,0);
    for(auto it:m)
        ans.push_back(it.second);
    return ans;
}
int main(){
    TreeNode* root = createTree();
    vector<int> ans = solve(root);
    for(auto it:ans)cout<<it<<" ";
}