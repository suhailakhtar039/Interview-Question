// Author : Suhail Akhtar
// Date : 06-10-22
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
queue<int> s;

void BSTIterator(TreeNode *root)
{
if(root==NULL) return;
BSTIterator(root->left);
s.push(root->val);
BSTIterator(root->right);
}

/** @return whether we have a next smallest number */
bool hasNext()
{
return s.size()>0;
}

/** @return the next smallest number */
int next()
{
int temp=s.front();
s.pop();
return temp;
}

int main(){

}