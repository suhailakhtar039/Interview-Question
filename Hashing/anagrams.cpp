// Author : Suhail Akhtar
// Date : 20-09-22
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> solve(vector<string> v){
    vector<vector<int>> ans;
    int n=v.size();
    unordered_map<string,vector<int>> m;
    for(int i=0; i<n; i++){
        string temp = v[i];
        sort(temp.begin(),temp.end());
        m[temp].push_back(i+1);
    }
    for(auto it:m){
        vector<int> temp = it.second;
        ans.push_back(temp);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n;cin>>n;
    vector<string> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    vector<vector<int>> ans = solve(v);
    for(auto it:ans){
        for(auto ij:it)
            cout<<ij<<" ";
        cout<<endl;
    }
}