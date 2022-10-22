// Author : Suhail Akhtar
// Date : 22-10-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> v){
    int n = v.size();
    if(!n)return 0;
    int m = v[0].size();
    int ans = v[0][0];
    for(int j=0; j<m; j++){
        if(j-2>=0){
            int preMax = max(v[0][j-2],v[1][j-2]);
            v[0][j]+=preMax;
            v[1][j]+=preMax;
        }
        ans = max(ans,v[0][j],v[1][j]);
    }
    return ans;
}
int main(){
    int n;cin>>n;
    vector<vector<int>> v(2,vector<int>(n,0));
    for(int i=0; i<2; i++)
    for(int j=0; j<n; j++)cin>>v[i][j];
    cout<<solve(v);
}