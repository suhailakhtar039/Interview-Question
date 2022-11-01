// Author : Suhail Akhtar
// Date : 01-11-22
#include <bits/stdc++.h>
using namespace std;
int solve(int n,vector<vector<int>> v){
    int m = v.size();
    vector<pair<int,int>> adj[n+1];
    for(int i=0; i<m; i++){
        int x = v[i][0], y = v[i][1], w = v[i][2];
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    int src = 1;
    vector<int> key(n+1,INT_MAX);
    vector<bool> inMST(n+1,false);
    key[src]=0;
    int ans = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        int u = pq.top().second;pq.pop();
        // cout<<" u = "<<u<<endl;
        if(inMST[u])continue;
        inMST[u]=true;
        for(auto i:adj[u]){
            int v = i.first;
            int w = i.second;
            if(!inMST[v] && key[v]>w){
                key[v]=w;
                pq.push({key[v],v});
            }
        }
    }
    for(int j=1; j<=n; j++){
        ans+=key[j];
        // cout<<"j : "<<j<<" keyJ : "<<key[j]<<endl;
    }
    return ans;
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(m,vector<int>(3,0));
    for(int i=0; i<m; i++){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    cout<<solve(n,v);
}