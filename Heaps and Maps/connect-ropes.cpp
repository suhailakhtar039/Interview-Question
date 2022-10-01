// Author : Suhail Akhtar
// Date : 30-09-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> v){
    int n=v.size();
    priority_queue<int,vector<int>, greater<int>> pq;
    int ans=0;
    for(int i:v)pq.push(i);
    while(pq.size()!=1){
        int firstRope = pq.top();pq.pop();
        if(pq.size()==0){
            ans+=firstRope;
        }
        int secondRope = pq.top();pq.pop();
        int totalCost = firstRope+secondRope;
        ans+=totalCost;
        // cout<<"first rope = "<<firstRope<<" second rope = "<<secondRope<<" total cost = "<<totalCost<<endl;
        pq.push(totalCost);
    }
    return ans;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v);
}