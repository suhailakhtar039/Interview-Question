// Author : Suhail Akhtar
// Date : 27-10-22
#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
void dfs(vector<int> &A,vector<int> g[],unordered_map<int,bool> &vis,int src,int c,int goodPath){
    if(vis.count(src))return;
    vis[src]=true;
    bool leaf = true;
    goodPath+=A[src-1];
    for(auto i:g[src]){
        if(vis.count(i)==false){
            leaf = false;
            dfs(A,g,vis,i,c,goodPath);
        }
    }
    if(leaf){
        if(goodPath<=c){
            cnt++;
        }
    }
}
int solve(vector<int> A,vector<vector<int>> v,int c){
    cnt = 0;
    int n = A.size();
    int sz = v.size();
    vector<int> g[n+1];
    for(int i=0; i<v.size(); i++){
        g[v[i][0]].push_back(v[i][1]);
        g[v[i][1]].push_back(v[i][0]);
    }
    unordered_map<int,bool> vis;
    dfs(A,g,vis,1,c,0);
    return cnt;
}
int main(){
    int n,m,c;cin>>n>>m>>c;
    vector<int> a(n,0);
    for(int i=0; i<n; i++)cin>>a[i];
    vector<vector<int>> v(m,vector<int>(2,0));
    for(int i=0; i<m; i++)cin>>v[i][0]>>v[i][1];
    cout<<solve(a,v,c);
}