// Author : Suhail Akhtar
// Date : 29-08-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> A){
    int n=A.size();
    if(n<=1)return n;
    int cnt=0;
    for(int i=0; i<n-1; i++){
        if(A[i]!=A[i+1])
            A[cnt++]=A[i];
    }
    A[cnt++]=A[n-1];
    return cnt;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v);
}