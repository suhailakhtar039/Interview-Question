// Author : Suhail Akhtar
// Date : 01-11-22
#include <bits/stdc++.h>
using namespace std;
int par[100001],sze[100001];
int findPar(int x){
    if(x==par[x])return x;
    return par[x]=findPar(par[x]);
}
void add(int x,int y){
    int parx = findPar(x),pary = findPar(y);
    if(parx!=pary){
        int szx = sze[parx],szy = sze[pary];
        if(szx>szy){
            par[pary]=parx;
            sze[parx]+=sze[pary];
        }else{
            par[parx]=pary;
            sze[pary]+=sze[parx];
        }
    }
}
int solve(vector<int> a,vector<int> b,vector<vector<int>> v){
    int m = v.size();
    int n = a.size();
    for(int i=0; i<n; i++){
        sze[i]=1;
        par[i]=i;
    }
    for(int i=0; i<m; i++){
        add(a[v[i][0]-1],a[v[i][1]-1]);
    }
    for(int i=0; i<n; i++){
        if(a[i]!=b[i] && findPar(a[i])!=findPar(b[i]))
            return false;
    }
    return true;
}
int main(){
    int n,m;cin>>n>>m;
    vector<int> a(n),b(n);
    vector<vector<int>> v(m,vector<int>(2,0));
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<n; i++)cin>>b[i];
    for(int i=0; i<m; i++){
        cin>>v[i][0]>>v[i][1];
    }
    cout<<solve(a,b,v);
}