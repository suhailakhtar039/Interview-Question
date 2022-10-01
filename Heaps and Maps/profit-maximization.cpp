// Author : Suhail Akhtar
// Date : 30-09-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>v ,int k){
    int ans=0;
    priority_queue<int> pq;
    for(auto it:v)pq.push(it);
    for(int i=0; i<k; i++){
        ans+=pq.top();
        int val = pq.top();pq.pop();
        val--;
        if(val)
            pq.push(val);
    }
    return ans;
}
int main(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v,k);
}