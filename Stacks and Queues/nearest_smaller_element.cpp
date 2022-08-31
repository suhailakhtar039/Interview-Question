// Author : Suhail Akhtar
// Date : 01-09-22
#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> v){
    int n = v.size();
    stack<int> s;
    vector<int> pre(n,0);
    pre[0]=-1;
    s.push(0);
    for(int i=1; i<n; i++){
        int val = v[i];
        while(!s.empty() && v[s.top()]>=val)s.pop();
        pre[i] = s.empty()?-1:v[s.top()];
        s.push(i);
    }
    return pre;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    vector<int> ans = solve(v);
    for(auto i:ans)cout<<i<<" ";
}