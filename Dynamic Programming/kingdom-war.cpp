// Author : Suhail Akhtar
// Date : 19-10-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> v){
    int n = v.size();
    int m = v[0].size();
    int res = INT_MIN;
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=n; i>=0; i--){
        for(int j=m; j>=0; j--){
            if(i==n || j==m)dp[i][j]=0;
            else{
                dp[i][j]=v[i][j]+dp[i+1][j]+dp[i][j+1]-dp[i+1][j+1];
                res = max(res,dp[i][j]);
            }
        }
    }
    return res;
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)cin>>v[i][j];
    cout<<solve(v);
}