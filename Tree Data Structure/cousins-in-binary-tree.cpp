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
vector<int> solve(TreeNode* root,int k){
    vector<int> ans;
    queue<TreeNode*> q;
    if(root->val==k)return ans;
    q.push(root);
    bool found = false;
    while(!q.empty() && !found){
        int n = q.size();
        for(int i=1; i<=n; i++){
            TreeNode* f = q.front();q.pop();
            TreeNode *l = f->left, *r = f->right;
            if((l && l->val==k)||(r && r->val==k)){
                found = true;
            }else{
                if(l)q.push(l);
                if(r)q.push(r);
            }
        }
    }
    while (q.size()){
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}
int main(){
    TreeNode* root = createTree();
    int k; cin>>k;
    vector<int> ans = solve(root,k);
    for(auto i:ans)cout<<i<<" ";
}