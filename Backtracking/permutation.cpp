// Author : Suhail Akhtar
// Date : 14-09-22
#include<bits/stdc++.h>
using namespace std;
void findPermutation(vector<vector<int>> &ans,vector<int> v,int idx){
    if(idx == v.size()){
        ans.push_back(v);
        return;
    }
    for(int i = idx; i<v.size(); i++){
        swap(v[i],v[idx]);
        findPermutation(ans,v,idx+1);
        swap(v[i],v[idx]);
    }
}
vector<vector<int>> solve(vector<int> v){
    int n = v.size();
    vector<vector<int>> ans;
    findPermutation(ans,v,0);
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