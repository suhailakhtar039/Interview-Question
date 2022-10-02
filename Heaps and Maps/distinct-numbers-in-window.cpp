// Author : Suhail Akhtar
// Date : 02-10-22
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> v,int k){
    int n=v.size();
    if(k>n)return vector<int>{};
    unordered_map<int,int> m;
    vector<int> ans;
    for(int i=0; i<k; i++)
        m[v[i]]++;
    ans.push_back(m.size());
    for(int i=k; i<n; i++){
        int pre = v[i-k];
        m[pre]--;
        if(m[pre]==0)m.erase(pre);
        m[v[i]]++;
        ans.push_back(m.size());
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