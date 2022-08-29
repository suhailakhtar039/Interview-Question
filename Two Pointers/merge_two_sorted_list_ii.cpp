// Author : Suhail Akhtar
// Date : 29-08-22
#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &A,vector<int> &B){
    int n=A.size(),m=B.size();
    A.resize(n+m);
    vector<int> ans(n+m);
    int i=0,j=0,k=0;
    while (i<n && j<m)    {
        if(A[i]<B[j])
            ans[k++]=A[i++];
        else
            ans[k++]=B[j++];
    }
    while (i<n){
        ans[k++]=A[i++];
    }
    while(j<m){
        ans[k++]=B[j++];
    }
    A=ans;
}
int main(){
    int n,m;cin>>n>>m;
    vector<int> v1(n),v2(m);
    for(int i=0; i<n; i++)cin>>v1[i];
    for(int i=0; i<m; i++)cin>>v2[i];
    solve(v1,v2);
    for(int i=0; i<v1.size(); i++){
        cout<<v1[i]<<" ";
    }
}