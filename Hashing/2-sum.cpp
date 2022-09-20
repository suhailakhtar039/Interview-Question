// Author : Suhail Akhtar
// Date : 20-09-22
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &v,int k){
    int n = v.size();
    vector<int> ans;
    unordered_map<int,int> m;
    for(int i=0; i<n; i++){
        if(m.count(k-v[i])){
            ans.push_back(1+m[k-v[i]]);
            ans.push_back(1+i);
            return ans;
        }
        if(!m.count(v[i]))m[v[i]]=i;
    }
    return ans;
}
int main(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    vector<int> ans = solve(v,k);
    for(auto it:ans){
        cout<<it<<" ";
    }
}