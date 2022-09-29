// Author : Suhail Akhtar
// Date : 30-09-22
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> v,int k){
    priority_queue<int> pq;
    for(int i=0; i<v.size(); i++){
        pq.push(-1*v[i]);
        while(pq.size()>k)pq.pop();
    }
    vector<int> ans;
    while(pq.empty()==false){
        ans.push_back(-1*pq.top());
        pq.pop();
    }
    return ans;
}
int main(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    vector<int> ans = solve(v,k);
    for(auto it:ans)
        cout<<it<<" ";
}