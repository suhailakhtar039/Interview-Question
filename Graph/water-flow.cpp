// Author : Suhail Akhtar
// Date : 26-10-22
#include <bits/stdc++.h>
using namespace std;
int x[]={0,0,-1,+1};
int y[]={-1,+1,0,0};
bool isSafe(int i,int j,int &n,int &m,vector<vector<int>> &vis){
    return i>=0 && i<n && j>=0 && j<m && !vis[i][j];
}
void bfs(vector<vector<int>> &v,queue<pair<int,int>> &q, vector<vector<int>> &vis){
    int n = v.size();
    int m = v[0].size();
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        int a = p.first, b = p.second;
        vis[p.first][p.second]=1;
        for(int i=0; i<5; i++){
            int x1 = a+x[i], y1 = b+y[i];
            if(isSafe(x1,y1,n,m,vis) && v[x1][y1]>=v[a][b]){
                vis[x1][y1]=true;
                q.push({x1,y1});
            }
        }
    }
}
int solve(vector<vector<int>> v){
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> vis1(n,vector<int>(m,0));
    vector<vector<int>> vis2(n,vector<int>(m,0));
    queue<pair<int,int>> q1;
    queue<pair<int,int>> q2;
    for(int j=0; j<m; j++){
        q1.push({0,j});
        q2.push({n-1,j});
    }
    for(int i=0; i<n-1; i++){
        q1.push({i+1,0});
        q2.push({i,m-1});
    }
    bfs(v,q1,vis1);
    bfs(v,q2,vis2);
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis1[i][j] && vis2[i][j])
                ans++;
        }
    }
    return ans;
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)cin>>v[i][j];
    cout<<solve(v);
}