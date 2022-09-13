// Author : Suhail Akhtar
// Date : 14-09-22
#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &ans, vector<int> temp,vector<int> v,int idx){
    // cout<<"idx = "<<idx<<endl;
    ans.push_back(temp);
    int n=v.size();
    for(int i=idx; i<n; i++){
        // keep the first element
        // cout<<" i= "<<i<<" idx= "<<idx<<endl;
        temp.push_back(v[i]);
        // for(auto it:temp)cout<<it<<" ";cout<<endl;
        helper(ans,temp,v,i+1);
        temp.pop_back();
        // discard the first element
        // helper(ans,temp,v,idx+1);
    }
}

vector<vector<int>> solve(vector<int> v){
    vector<vector<int>> ans;
    vector<int> temp;
    sort(temp.begin(),temp.end());
    helper(ans,temp,v,0);
    return ans;
}

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    vector<vector<int>> ans = solve(v);
    for(auto it:ans){
        for(auto ij:it)
            cout<<ij<<" ";
        cout<<endl;
    }
}