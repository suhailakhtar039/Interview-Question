// Author : Suhail Akhtar
// Date : 20-10-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> v){
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> res(n,vector<int>(m,0));
    res[0][0]=1;
    for(int i=1; i<n; i++){
        if(v[i][0]>v[i-1][0])res[i][0] = 1+res[i-1][0];
        else break;
    }
    for(int j=1; j<m; j++){
        if(v[0][j]>v[0][j-1])res[0][j] = 1+res[j-1][0];
        else break;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            int mx = 0;
            if(v[i][j]>v[i-1][j])mx=max(mx,res[i-1][j]);
            if(v[i][j]>v[i][j-1])mx=max(mx,res[i][j-1]);
            if(mx)res[i][j]=1+mx;
        }
    }
    return res[n-1][m-1]==0?-1:res[n-1][m-1];
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)cin>>v[i][j];
    cout<<solve(v);
}