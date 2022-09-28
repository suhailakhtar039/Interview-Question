// Author : Suhail Akhtar
// Date : 29-09-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &v,int k){
    int n=v.size();
    int preXor[n];
    int ans=0;
    unordered_map<int,int> m;
    preXor[0]=v[0];
    for(int i=1; i<n; i++)
        preXor[i]=preXor[i-1]^v[i];
    for(int i=0; i<n; i++){
        int t = preXor[i]^k;
        if(m.count(t))
            ans+=m[t];
        if(preXor[i]==k)ans++;
        m[preXor[i]]++;
    }
    return ans;
}
int main(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v,k);
}