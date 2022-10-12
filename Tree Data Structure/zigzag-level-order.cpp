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
vector<vector<int>> solve(TreeNode* root){
    vector<vector<int>> ans;
    if(!root)return ans;
    queue<TreeNode*> q;
    q.push(root);
    bool left = false;
    while(q.size()){
        int n = q.size();
        vector<int> temp;
        for(int i=1; i<=n; i++){
            TreeNode *f = q.front();q.pop();
            temp.push_back(f->val);
            if(f->left)q.push(f->left);
            if(f->right)q.push(f->right);
        }
        if(left)
            reverse(temp.begin(),temp.end());
        left = !left;
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    TreeNode *root = createTree();
    for(auto i:solve(root)){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
}