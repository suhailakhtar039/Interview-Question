// Author : Suhail Akhtar
// Date : 19-10-22
#include<bits/stdc++.h>
using namespace std;
int memo[501][501];
int mxpoints(vector<int> &v,int st,int en){
    if(en<st || st>=v.size() || en<0)return 0;
    if(memo[st][en]!=-1)return memo[st][en];
    if(en==st)return v[st];
    if(en==st+1)return max(v[st],v[en]);
    int firstCoin = v[st]+min(mxpoints(v,st+2,en),mxpoints(v,st+1,en-1));
    int lastCoin = v[en]+min(mxpoints(v,st,en-2),mxpoints(v,st+1,en-1));
    return memo[st][en] = max(firstCoin,lastCoin);
}
int solve(vector<int> v){
    int n = v.size();
    for(int i=0; i<=500; i++)
    for(int j=0; j<=500; j++)memo[i][j]=-1;
    return mxpoints(v,0,n-1);
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v);
}