// Author : Suhail Akhtar
// Date : 21-10-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> v){
    int n = v.size();
    if(!n)return 0;
    int m = v[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    if(v[0][0]==1)return 0;
    for(int i=1; i<m; i++)
        if(v[0][i]==1)break;
        else dp[0][i]=1;
    for(int i=1; i<n; i++)
        if(v[i][0]==1)break;
        else dp[i][0]=1;
    dp[0][0]=1;
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++)
            if(!v[i][j])
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
    return dp[n-1][m-1];
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)cin>>v[i][j];
    cout<<solve(v);
}