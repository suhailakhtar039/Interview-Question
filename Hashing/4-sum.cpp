// Author : Suhail Akhtar
// Date : 20-09-22
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> solve(vector<int> &v,int k){
    vector<vector<int>> ans;
    int n = v.size();
    unordered_map<int,pair<int,int>> m;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            m[v[i]+v[j]]={i,j};
        }
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int sum = k-v[i]-v[j];
            if(m.count(sum)){
                int i1=m[sum].first,j1=m[sum].second;
                if(i!=i1 && i!=j1 && j!=i1 && j!=j1){
                    vector<int> temp;
                    temp.push_back(v[i]);
                    temp.push_back(v[j]);
                    temp.push_back(v[i1]);
                    temp.push_back(v[j1]);
                    sort(temp.begin(),temp.end());
                    ans.push_back(temp);
                }
            }
        }
    }
    set<vector<int>> s;
    for(auto it:ans)s.insert(it);
    ans.clear();
    for(auto it:s)ans.push_back(it);
    return ans;
}
int main(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    vector<vector<int>> ans = solve(v,k);
    for(auto it:ans){
        for(auto ij:it){
            cout<<ij<<" ";
        }cout<<endl;
    }
}