// Author : Suhail Akhtar
// Date : 02-10-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> A,int index =0,int low=INT_MIN,int high=INT_MAX){
    if(index >= A.size()) return; //preorder vector exhausted, means whole tree can be created

    if(A[index] <= low || A[index] >= high) return; // it means element cannot be pushed to either left or right

                                                    // by returning checking for parent node, to push element at right

    int root = A[index]; // value of root for limits

    index++;

    solve(A, index, low, root); //left call, higher limit will be root's data

    solve(A, index, root, high); //right call, lower limit will be root's data
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    cout<<solve(v);
}