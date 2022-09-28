// Author : Suhail Akhtar
// Date : 22-09-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> v){
    int n=v.size();
    unordered_set<int> s;
    int ans=0;
    for(int i=0; i<n; i++){
        s.insert(v[i]);
    }
    for(int i=0; i<n; i++){
        if(s.find(v[i]-1)==s.end()){
            int j = v[i];
            while(s.find(j)!=s.end())j++;
            ans = max(ans,j-v[i]);
        }
    }
    return ans;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v);
}