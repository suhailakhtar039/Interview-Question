// Author : Suhail Akhtar
// Date : 27-10-22
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],int src,vector<int> &dist,vector<bool> &vis){
    if(vis[src])return;
    vis[src]=true;
    for(auto i:adj[src]){
        if(!vis[i]){
            dist[i]=max(dist[i],1+dist[src]);
            dfs(adj,i,dist,vis);
        }
    }
}
int solve(vector<int> v){
    int n = v.size();
    vector<int> adj[n];
    int src;
    for(int i=0; i<n; i++){
        if(v[i]==-1)src=i;
        else{
            adj[i].push_back(v[i]);
            adj[v[i]].push_back(i);
        }
    }
    vector<int> dist(n+1,-1);
    vector<bool> vis(n+1,false);
    dist[src]=0;
    dfs(adj,src,dist,vis);
    int highestNode;
    // cout<<"src = "<<src<<endl;
    // for(int i=0; i<n; i++){
    //     cout<<"i: "<<i<<" dist: "<<dist[i]<<endl;
    // }
    int mx = *max_element(dist.begin(),dist.end());
    for(int i=0; i<n; i++){
        if(dist[i]==mx){
            highestNode = i;
            break;
        }
    }
    fill(dist.begin(),dist.end(),-1);
    fill(vis.begin(),vis.end(),false);
    // for(int i=0; i<n; i++){
    //     cout<<"i: "<<i<<" dist: "<<dist[i]<<endl;
    // }
    dist[highestNode]=0;
    dfs(adj,highestNode,dist,vis);
    // cout<<"highestNode = "<<highestNode<<endl;
    // for(int i=0; i<n; i++){
    //     cout<<"i: "<<i<<" dist: "<<dist[i]<<endl;
    // }
    return *max_element(dist.begin(),dist.end());
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v);
}