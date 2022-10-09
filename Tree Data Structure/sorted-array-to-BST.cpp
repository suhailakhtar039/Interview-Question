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
TreeNode* createFromArray(vector<int> &v,int low,int high){
    if(high<low)return NULL;
    if(high==low)return new TreeNode(v[low]);
    int mid = (low+high)/2;
    TreeNode* root = new TreeNode(v[mid]);
    root->left = createFromArray(v,low,mid-1);
    root->right = createFromArray(v,mid+1,high);
    return root;
}
TreeNode* solve(vector<int> v){
    int n = v.size();
    int lo = 0,hi = n-1;
    TreeNode* root = createFromArray(v,lo,hi);
    return root;
}

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    TreeNode* ans = solve(v);
    preorder(ans);
}