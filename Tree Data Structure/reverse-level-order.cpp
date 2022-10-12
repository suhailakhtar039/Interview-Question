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
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> store;
    while(q.size()){
        int n = q.size();
        for(int i=1; i<=n; i++){
            TreeNode* f = q.front();q.pop();
            if(f->left)q.push(f->left);
            if(f->right)q.push(f->right);
            ans.push_back(f->val);
        }
        store.push_back(ans);
        ans.clear();
    }
    reverse(store.begin(),store.end());
    for(auto it:store){
        for(auto ij:it)
            ans.push_back(ij);
    }
    return ans;
}
int main(){
    TreeNode* root = createTree();
    vector<int> ans = solve(root);
    for(auto i:ans)cout<<i<<" ";
}