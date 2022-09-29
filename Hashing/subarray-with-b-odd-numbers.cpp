// Author : Suhail Akhtar
// Date : 29-09-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> v,int k){
    unordered_map<int,int> m;
    int ans=0,sum=0;
    for(int i=0; i<v.size(); i++){
        sum+=v[i]%2;
        if(sum==k)ans++;
        if(m.count(sum-k))
            ans+=m[sum-k];
        m[sum]++;
    }
    return ans;
}
int main(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v,k);
}