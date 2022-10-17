// Author : Suhail Akhtar
// Date : 17-10-22
#include<bits/stdc++.h>
using namespace std;
vector<int> findLongestIncreasing(vector<int> &v){
    int n = v.size();
    vector<int> lis(n,1);
    for(int i=1; i<n; i++){
        int len = -1;
        for(int j=0; j<i; j++){
            if(v[j]<v[i]){
                len=max(len,lis[j]);
            }
        }
        if(len==-1){
            lis[i]=1;
        }else{
            lis[i]=len+1;
        }
    }
    return lis;
}
int solve(vector<int> &v){
    int n = v.size();
    vector<int> pre,suf;
    pre = findLongestIncreasing(v);
    reverse(v.begin(),v.end());
    suf = findLongestIncreasing(v);
    int ans = 1;
    reverse(suf.begin(),suf.end());
    for(int i=0; i<n; i++){
        ans=max(ans,pre[i]+suf[i]-1);
    }
    return ans;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v);
}