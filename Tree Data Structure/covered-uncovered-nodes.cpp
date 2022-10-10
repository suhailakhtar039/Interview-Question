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
long totalSum(TreeNode* root){
    if(!root)return 0l;
    return root->val+totalSum(root->left)+totalSum(root->right);
}
long leftSum(TreeNode* root){
    if(!root)return 0l;
    if(root->left==NULL && root->right==NULL)return root->val;
    if(root->left!=NULL)return root->val+leftSum(root->left);
    else return root->val+leftSum(root->right);
}
long rightSum(TreeNode* root){
    if(!root)return 0l;
    if(root->left==NULL && root->right==NULL)return root->val;
    if(root->right!=NULL)return root->val+rightSum(root->right);
    else return root->val+rightSum(root->left);
}
long solve(TreeNode* root){
    // boundary sum
    long lsum = root->left!=NULL?leftSum(root->left):0;
    long rsum = root->right!=NULL?rightSum(root->right):0;
    long bsum = lsum+rsum+root->val;
    // cout<<"lsum = "<<lsum<<endl;
    // cout<<"rsum = "<<rsum<<endl;
    // cout<<"bsum = "<<bsum<<endl;
    long tsum = totalSum(root);
    long usum = tsum-bsum;
    return abs(bsum-usum);
}
// alternate way
long coveredNodes(TreeNode* A) {
    queue<TreeNode*>q;
    q.push(A);
    set<TreeNode*>s1;
    set<TreeNode*>s2;
   
    while(!q.empty())
    {
        int n=q.size();
       
        for(int i=0;i<n;i++)
        {
            TreeNode* t=q.front();
            q.pop();
            if(i==0 || i==n-1)
            s1.insert(t);
            else
            s2.insert(t);
            if(t->left)
            q.push(t->left);
            if(t->right)
            q.push(t->right);
        }
    }
    long l1=0;
    long l2=0;
    for(auto it:s1)
    l1+=it->val;
    for(auto it:s2)
    l2+=it->val;
    return (long)((long)abs((long)l1-(long)l2));
}
int main(){
    TreeNode* root = createTree();
    long ans = solve(root);
    cout<<ans<<endl;
}