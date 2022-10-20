// Author : Suhail Akhtar
// Date : 20-10-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> v){
    int n = v.size();
    if(!n)return 0;
    int m = v[0].size();
    vector<vector<int>> res = v;
    int ans = 0;
    for(int i=0; i<n; i++)
        if(v[i][0])ans = 1;
    for(int j=0; j<m; j++)
        if(v[0][j])ans = 1;
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(res[i][j]==1)
                res[i][j]=min(res[i-1][j],min(res[i][j-1],res[i-1][j-1]))+1;
            else
                res[i][j]=0;
            
            ans = max(ans,res[i][j]);
        }
    }
    return ans*ans;
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)cin>>v[i][j];
    cout<<solve(v);
}