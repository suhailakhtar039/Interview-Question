// Author : Suhail Akhtar
// Date : 30-09-22
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<vector<int>> v){
    int n = v.size();
    int m = v[0].size();
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> ans;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            pq.push(v[i][j]);
        }
    }
    while(pq.size()!=0){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin>>v[i][j];
    }
    vector<int> ans = solve(v);
    for(auto it:ans)
        cout<<it<<" ";
}