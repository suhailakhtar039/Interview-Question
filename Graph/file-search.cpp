// Author : Suhail Akhtar
// Date : 02-11-22
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],vector<bool> &vis,int src){
    if(vis[src])return;
    vis[src]=true;
    for(auto i:adj[src]){
        if(!vis[i])
            dfs(adj,vis,i);
    }
}
int solve(int n,vector<vector<int>> v){
    int m = v.size();
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        adj[v[i][0]].push_back(v[i][1]);
        adj[v[i][1]].push_back(v[i][0]);
    }
    vector<bool> vis(n+1,false);
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            cnt++;
            dfs(adj,vis,i);
        }
    }
    return cnt;
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(m,vector<int>(2,0));
    for(int i=0; i<m; i++)cin>>v[i][0]>>v[i][1];
    cout<<solve(n,v);
}