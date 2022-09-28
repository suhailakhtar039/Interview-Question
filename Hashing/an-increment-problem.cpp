// Author : Suhail Akhtar
// Date : 28-09-22
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> v){
    int n=v.size();
    map<int,int> m;
    for(int i=0; i<n; i++){
        if(m.count(v[i])){
            int idx = m[v[i]];
            m.erase(v[i]);
            m[v[idx]+1]=idx;
            v[idx]++;
            m[v[i]]=i;
        }else
            m[v[i]]=i;
        // cout<<"i = "<<i<<endl;
        // for(auto it:m){
        //     cout<<it.first<<" : "<<it.second<<endl;
        // }
        // cout<<"elements: ";
        // for(auto it:v)cout<<it<<" ";
        // cout<<endl<<endl;
    }
    return v;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    vector<int> ans = solve(v);
    for(auto i:ans){
        cout<<i<<" ";
    }
}