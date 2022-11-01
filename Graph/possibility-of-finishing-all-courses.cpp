// Author : Suhail Akhtar
// Date : 01-11-22
#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int> adj[],int src,vector<int> &vis,vector<int> &rec){
    if(vis[src]==false){
        // cout<<" src = "<<src<<" vis = "<<vis[src]<<" rec = "<<rec[src]<<endl;
        vis[src]=true;
        rec[src]=true;
        for(auto i:adj[src]){
            if(!vis[i] && dfs(adj,i,vis,rec))
                return true;
            else if(rec[i])
                return true;
        }
    }
    rec[src]=false;
    return false;
}
int solve(int n,vector<int> a,vector<int> b){
    int m = a.size();
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        adj[a[i]].push_back(b[i]);
    }
    vector<int> vis(n+1,0);
    vector<int> rec(n+1,0);
    return 1-dfs(adj,1,vis,rec);
}
int main(){
    int n,m;cin>>n>>m;
    vector<int> a(m),b(m);
    for(int i=0; i<m; i++)cin>>a[i];
    for(int i=0; i<m; i++)cin>>b[i];
    cout<<solve(n,a,b)<<endl;
}