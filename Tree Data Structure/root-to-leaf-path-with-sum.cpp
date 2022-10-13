// Author : Suhail Akhtar
// Date : 13-10-22
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
void allPath(TreeNode *root,vector<vector<int>> &ans,vector<int> temp,int sum){
    if(!root)return ;
    if(root->left==NULL && root->right==NULL){
        sum-=root->val;
        if(sum==0){
            temp.push_back(root->val);
            ans.push_back(temp);
        }
        return;
    }
    temp.push_back(root->val);
    allPath(root->left,ans,temp,sum-root->val);
    allPath(root->right,ans,temp,sum-root->val);
    temp.pop_back();
}
vector<vector<int>> solve(TreeNode* root,int sum){
    vector<vector<int>> ans;
    vector<int> temp;
    allPath(root,ans,temp,sum);
    return ans;
}
int main(){
    TreeNode* root = createTree();
    int sum;cin>>sum;
    vector<vector<int>> ans = solve(root,sum);
    for(auto i:ans){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
}