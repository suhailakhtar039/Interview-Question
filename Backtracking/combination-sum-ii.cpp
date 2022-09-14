// Author : Suhail Akhtar
// Date : 15-09-22
#include<bits/stdc++.h>
using namespace std;
void helper(vector<vector<int>> &ans,vector<int> temp,vector<int> &v,int idx,int sum,int virtualSum=0){
    if(virtualSum>sum)return;
    if(virtualSum==sum){
        // cout<<"idx = "<<idx<<endl;
        ans.push_back(temp);
        return;
    }
    int n=v.size();
    // cout<<"idx = "<<idx<<" sum = "<<sum<<endl;
    for(int i=idx; i<n; i++){
        // cout<<"idx= "<<idx<<" i= "<<i<<" sum= "<<sum<<endl;
        // if(sum<0)return;
        temp.push_back(v[i]);
        helper(ans,temp,v,i+1,sum,virtualSum+v[i]);
        temp.pop_back();
    }
}
vector<vector<int>> solve(vector<int> v,int sum){
    vector<vector<int>> ans;
    vector<int> temp;
    sort(v.begin(),v.end());
    helper(ans,temp,v,0,sum);
    set<vector<int>> s;
    for(auto it:ans)s.insert(it);
    ans.clear();
    for(auto it:s)
    ans.push_back(it);
    // sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    int sum;cin>>sum;
    vector<vector<int>> ans = solve(v,sum);
    for(auto it:ans){
        for(auto ij:it)
            cout<<ij<<" ";
        cout<<endl;
    }
}