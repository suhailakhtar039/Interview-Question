// Author : Suhail Akhtar
// Date : 31-10-22
#include <bits/stdc++.h>
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
void preorder(TreeNode* root){
    if(root==NULL)return ;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
vector<vector<int>> solve(TreeNode* root){
    vector<vector<int>> ans;
    if(!root)return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int> temp;
        for(int i=0; i<n; i++){
            TreeNode* f = q.front();q.pop();
            temp.push_back(f->val);
            if(f->left)q.push(f->left);
            if(f->right)q.push(f->right);
        }
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    TreeNode* root = createTree();
    vector<vector<int>> ans = solve(root);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}