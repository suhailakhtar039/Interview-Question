// Author : Suhail Akhtar
// Date : 20-09-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> v,int k){
    int n=v.size();
    int ans=0;
    unordered_map<int,int> m;
    for(int i=0; i<n; i++){
        if(m.count(v[i]^k))ans++;
        m[v[i]]=1;
    }
    return ans;
}
int main(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v,k);
}