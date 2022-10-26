// Author : Suhail Akhtar
// Date : 26-10-22
#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int> adj[],vector<bool> &vis,int src,int dest){
    if(src==dest)return true;
    vis[src]=true;
    for(auto it:adj[src]){
        if(!vis[it] && dfs(adj,vis,it,dest)==true)
            return true;
    }
    return false;
}
int solve(int n,vector<vector<int>> v){
    vector<int> adj[n+1];
    vector<bool> vis(n+1,0);
    for(int i=0; i<v.size(); i++){
        adj[v[i][0]].push_back(v[i][1]);
    }
    return dfs(adj,vis,1,n);
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(m,vector<int>(2,0));
    for(int i=0; i<m; i++){
        cin>>v[i][0]>>v[i][1];
    }
    cout<<solve(n,v);
}