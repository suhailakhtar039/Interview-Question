// Author : Suhail Akhtar
// Date : 21-10-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> v){
    int n = v.size();
    if(!n)return 0;
    int m = v[0].size();
    for(int i=1; i<n; i++)
        v[i][0]+=v[i-1][0];
    for(int j=1; j<m; j++)
        v[0][j]+=v[0][j-1];

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++)
            v[i][j]+=min(v[i-1][j],v[i][j-1]);
    }
    return v[n-1][m-1];
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)cin>>v[i][j];
    cout<<solve(v);
}