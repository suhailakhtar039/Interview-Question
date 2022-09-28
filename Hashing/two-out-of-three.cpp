// Author : Suhail Akhtar
// Date : 29-09-22
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> v1,vector<int> v2,vector<int> v3){
    unordered_map<int,int> m;
    set<int> s;
    for(int i=0; i<v1.size(); i++)m[v1[i]]++;
    for(int i=0; i<v2.size(); i++)if(m.count(v2[i]))s.insert(v2[i]);
    for(int i=0; i<v3.size(); i++)if(m.count(v3[i]))s.insert(v3[i]);

    m.clear();
    for(int i=0; i<v2.size(); i++)m[v2[i]]++;
    for(int i=0; i<v3.size(); i++)if(m.count(v3[i]))s.insert(v3[i]);
    vector<int> ans(s.begin(),s.end());
    return ans;
}
int main(){
    int n,m,k;cin>>n>>m>>k;
    vector<int> v1(n),v2(m),v3(k);
    for(int i=0; i<n; i++)cin>>v1[i];
    for(int i=0; i<m; i++)cin>>v2[i];
    for(int i=0; i<k; i++)cin>>v3[i];
    vector<int> ans = solve(v1,v2,v3);
    for(auto it:ans)cout<<it<<" ";
}