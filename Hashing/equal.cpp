// Author : Suhail Akhtar
// Date : 22-09-22
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> v){
    int n=v.size();
    vector<vector<int>> ans;
    unordered_map<int,pair<int,int>> m;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int sum = v[i]+v[j];
            if(m.count(sum)){
                set<int> s; // set for checking duplicates , we want all 4 values to be different
                s.insert(m[sum].first);
                s.insert(m[sum].second);
                s.insert(i);
                s.insert(j);
                if(s.size()==4)
                ans.push_back({m[sum].first , m[sum].second , i , j});
            }else{
                m[sum]={i,j};
            }
        }
    }
    sort(ans.begin(),ans.end());
    if(ans.size())return ans[0];
    else return vector<int>{};
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    vector<int> ans = solve(v);
    for(auto it:ans)
        cout<<it<<" ";
}