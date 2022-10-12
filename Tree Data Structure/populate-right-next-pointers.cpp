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
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };
TreeLinkNode* getNextNode(TreeLinkNode* q){
    TreeLinkNode *temp = q->next;
    while(temp!=NULL){
        if(temp->left)return temp->left;
        if(temp->right)return temp->right;
        temp=temp->next;
    }
    return NULL;
}
void connect(TreeLinkNode* root) {
    TreeLinkNode* temp = root;
    root->next = NULL;
    while(temp){
        TreeLinkNode* q = temp;
        while(q){
            if(q->left){
                if(q->right)
                    q->left->next = q->right;
                else
                    q->left->next = getNextNode(q);
            }
            if(q->right){
                q->right->next = getNextNode(q);
            }
            q = q->next;
        }
        if(temp->left)temp = temp->left;
        else if(temp->right) temp = temp->right;
        else temp = getNextNode(temp);
    }
}

int main(){

}