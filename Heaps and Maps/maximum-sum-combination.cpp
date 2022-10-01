// Author : Suhail Akhtar
// Date : 30-09-22
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> v1,vector<int> v2,int k){
    int n = v1.size();
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> s;
    vector<int> ans;
    if(k==0)return vector<int>{};
    pq.push({v1[n-1]+v2[n-1],{n-1,n-1}});
    s.insert({n-1,n-1});
    while(k--){
        pair<int,pair<int,int>> p = pq.top();pq.pop();
        ans.push_back(p.first);
        int i = p.second.first;
        int j = p.second.second;
        int sum = v1[i-1]+v2[j];
        if(s.find({i-1,j})==s.end()){
            pq.push({v1[i-1]+v2[j],{i-1,j}});
            s.insert({i-1,j});
        }
        sum = v1[i]+v2[j-1];
        if(s.find({i,j-1})==s.end()){
            pq.push({v1[i]+v2[j-1],{i,j-1}});
            s.insert({i,j-1});
        }
    }
    return ans;
}
int main(){
    int n,k;cin>>n>>k;
    vector<int> v1(n),v2(n);
    for(int i=0; i<n; i++)cin>>v1[i];
    for(int i=0; i<n; i++)cin>>v2[i];
    vector<int> ans = solve(v1,v2,k);
    for(auto it:ans)
        cout<<it<<" ";
}