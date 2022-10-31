// Author : Suhail Akhtar
// Date : 31-10-22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<int,pair<int,int>>
int solve(vector<string> v,int a,int b){
    vector<vector<ll>> dist(a,vector<ll>(b,INT_MAX));
    dist[0][0]=0;
    int goX[]={-1,+1,0,0};
    int goY[]={0,0,-1,+1};
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    pq.push({0,{0,0}});
    while(!pq.empty()){
        auto f = pq.top();pq.pop();
        int d = f.first;
        int i = f.second.first;
        int j = f.second.second;
        int dir = 0;
        if(v[i][j]=='U')dir = 0;
        else if(v[i][j]=='D')dir = 1;
        else if(v[i][j]=='L')dir = 2;
        else dir = 3;
        char orVal = v[i][j];
        for(int k=0; k<4; k++){
            int x = i + goX[k];
            int y = j + goY[k];
            if(x>=0 && x<a && y>=0 && y<b){
                if(dir == k){
                    if(dist[x][y]>dist[i][j]){
                        dist[x][y]=dist[i][j];
                        pq.push({dist[x][y],{x,y}});
                    }
                }else{
                    if(dist[x][y]>dist[i][j]+1){
                        dist[x][y]=dist[i][j]+1;
                        pq.push({dist[x][y],{x,y}});
                    }
                }
            }
        }
    }
    return dist[a-1][b-1];
}
int main(){
    int a,b;cin>>a>>b;
    vector<string> v(a);
    for(int i=0; i<a; i++)
        cin>>v[i];
    cout<<solve(v,a,b);
}