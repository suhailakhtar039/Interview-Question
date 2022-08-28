// Author : Suhail Akhtar
// Date : 28-08-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> A){
    sort(A.begin(),A.end());
    int ans = INT_MAX;
    for(int i=0; i<A.size()-1; i++)
        ans=min(ans,A[i]^A[i+1]);
    return ans;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v);
}