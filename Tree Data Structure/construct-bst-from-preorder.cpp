// Author : Suhail Akhtar
// Date : 08-10-22
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
TreeNode* solve(vector<int> A){
    stack<TreeNode*> st;
    TreeNode* root=new TreeNode(A[0]);
    TreeNode* res=root;
    st.push(root);
    for(int i=1;i<A.size();i++){
        TreeNode* prev=NULL;
        while(!st.empty() && st.top()->val<=A[i]){
            prev=st.top();
            st.pop();
        }
        TreeNode* curr=new TreeNode(A[i]);
        if(prev)   prev->right=curr;
        else    st.top()->left=curr;
        st.push(curr);
    }
    return res;
}

// ==============
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    TreeNode* root = solve(v);
    preorder(root);
}