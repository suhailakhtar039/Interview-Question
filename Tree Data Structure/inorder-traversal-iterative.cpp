// Author : Suhail Akhtar
// Date : 11-10-22
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
void inorder(TreeNode* root){
    if(root==NULL)return ;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
vector<int> solve(TreeNode* root){
    vector<int> v;
    if(!root)return v;
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while(curr!=NULL || s.empty()==false){
        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr=s.top();s.pop();
        v.push_back(curr->val);
        curr = curr->right;
    }
    return v;
}
int main(){
    TreeNode* root = createTree();
    vector<int> v = solve(root);
    for(auto it:v)
        cout<<it<<" ";cout<<endl;
    inorder(root);
}