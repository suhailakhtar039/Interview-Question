// Author : Suhail Akhtar
// Date : 14-10-22
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
void merge(vector<int> &A, int low, int mid, int high, int &ans) {

vector<int> aux(high-low+1);

int i=low, j=mid+1,k=0;

while(i <= mid && j <= high) {

if(A[i] > A[j]) {

aux[k++] = A[j++];

ans += mid - i  + 1;

} else {

aux[k++] = A[i++];

}

}

while(i <= mid) {

aux[k++] = A[i++];

}

while(j <= high) {

aux[k++] = A[j++];

}

k=0;

for( i=low;i<=high;i++) {

A[i] = aux[k++];

}

}

void mergeSort(vector<int> &A, int low, int high, int &ans){

if(low < high) {

int mid = low + (high - low)/2;

mergeSort(A, low, mid, ans);

mergeSort(A, mid+1, high, ans);

merge(A, low, mid, high, ans);

}

}

int countInversions(vector<int> &A) {

int ans=0;

mergeSort(A, 0, A.size()-1, ans);

return ans;

}
int main(){
    
}