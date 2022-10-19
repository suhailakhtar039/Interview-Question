// Author : Suhail Akhtar
// Date : 19-10-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> v){
    int n = v.size();
    if(n==0)return 0;
    int res = v[0][0];
    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            int mx = 0;
            mx=max(mx,v[i-1][j]);
            mx=max(mx,j-1>=0?v[i-1][j-1]:0);
            v[i][j]+=mx;
            res = max(res,v[i][j]);
        }
    }
    return res;
}
int main(){
    int n;cin>>n;
    vector<vector<int>> v(n,vector<int>(n,0));
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)cin>>v[i][j];
    cout<<solve(v);
}