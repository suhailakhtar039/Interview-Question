// Author : Suhail Akhtar
// Date : 19-10-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> a){
    unordered_map<int, int> mp;
    int n = a.size();
    if(n <=2)
    return n;
    int dp[1001][1001];
    int maxi = 2;
    for(int i=0; i<n-1; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            dp[i][j] = 2;
            int need = 2*a[i] - a[j];
            if(mp.find(need)!=mp.end())
            {
                dp[i][j] = max(dp[i][j], 1 + dp[mp[need]][i]);
                maxi = max(maxi, dp[i][j]);
            }
        }
        mp[a[i]] = i;
    }
    return maxi;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v);
}