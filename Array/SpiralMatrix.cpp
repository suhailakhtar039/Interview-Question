// Author : Suhail Akhtar
// Date : 29-01-23
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<vector<int>> v){
    int n = v.size();
    if(n == 0)return vector<int>();
    int m = v[0].size();
    int up = 0, left = 0, right = m-1, down = n-1;
    vector<int> ans;
    while(up<=down && left<=right){
        for(int i=left; i<=right; i++)
            ans.push_back(v[up][i]);
        up++;
        if(up>down || left>right)break;
        for(int i=up; i<=down; i++)
            ans.push_back(v[i][right]);
        right--;
        if(up>down || left>right)break;
        for(int i=right; i>=left; i--)
            ans.push_back(v[down][i]);
        down--;
        if(up>down || left>right)break;
        for(int i=down; i>=up; i--)
            ans.push_back(v[i][left]);
        left++;
        if(up>down || left>right)break;
    }
    return ans;
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>v[i][j];
    for(auto i: solve(v))
        cout<<i<<" ";
}