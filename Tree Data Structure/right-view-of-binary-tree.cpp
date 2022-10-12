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
vector<int> solve(TreeNode* root){
    queue<TreeNode*> q;
    vector<int> ans;
    q.push(root);
    while(q.size()!=0){
        int n = q.size();
        for(int i=1; i<=n; i++){
            TreeNode* f = q.front();q.pop();
            if(f->left)q.push(f->left);
            if(f->right)q.push(f->right);
            if(i==n)ans.push_back(f->val);
        }
    }
    return ans;
}
int main(){
    TreeNode* root = createTree();
    vector<int> v = solve(root);
    for(auto it:v)cout<<it<<" ";
}