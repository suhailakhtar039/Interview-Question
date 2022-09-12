// Author : Suhail Akhtar
// Date : 12-09-22
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> v){
    int n = v.size();
    stack<int> s;
    vector<int> ans(n);
    for(int i=n-1; i>=0; i--){
        while(s.size()!=0 && v[i]>=v[s.top()])s.pop();
        ans[i]=s.empty()?-1:v[s.top()];
        s.push(i);
    }
    return ans;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    vector<int> ans = solve(v);
    for(const auto &it:ans)
        cout<<it<<" ";
}