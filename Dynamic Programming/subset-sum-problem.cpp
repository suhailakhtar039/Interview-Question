// Author : Suhail Akhtar
// Date : 20-10-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> v,int sum){
    int n = v.size();
    bool dp[n+1][sum+1];
    for(int i=0; i<=n; i++)
        dp[i][0]=1;
    for(int j=0; j<=sum; j++)
        dp[0][j]=0;
    dp[0][0]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(v[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]||dp[i-1][j-v[i-1]];
        }
    }
    return dp[n][sum];
}
int main(){
    int n,sum;cin>>n>>sum;
    vector<int> v(n);
    for(int i=0;i<n; i++)cin>>v[i];
    cout<<solve(v,sum);
}