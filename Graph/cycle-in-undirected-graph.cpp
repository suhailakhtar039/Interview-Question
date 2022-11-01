// Author : Suhail Akhtar
// Date : 01-11-22
#include <bits/stdc++.h>
using namespace std;
bool bfs(int src,vector<int> adj[],vector<int> &parent,vector<bool> &vis){
    queue<int> q;
    q.push(src);
    parent[src]=src;
    vis[src]=true;
    while(!q.empty()){
        int f = q.front();q.pop();
        for(auto i:adj[f]){
            if(vis[i]==false){
                vis[i]=true;
                parent[i]=f;
                q.push(i);
            }else{
                if(i!=parent[f])
                    return true;
            }
        }
    }
    return false;
}
int solve(int n,vector<vector<int>> v){
    int m = v.size();
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        adj[v[i][0]].push_back(v[i][1]);
        adj[v[i][1]].push_back(v[i][0]);
    }
    vector<int> parent(n+1,-1);
    vector<bool> vis(n+1,false);
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(vis[i]==false){
            bool cyc = bfs(i,adj,parent,vis);
            if(cyc)return true;
        }
    }
    return false;
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(m,vector<int>(2,0));
    for(int i=0; i<m; i++)
        cin>>v[i][0]>>v[i][1];
    cout<<solve(n,v);
}