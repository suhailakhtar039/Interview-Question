// Author : Suhail Akhtar
// Date : 29-08-22
#include <bits/stdc++.h>
using namespace std;
int atMostBelements(vector<int> v,int b){
    int ans=0;
    int left=0;
    unordered_map<int,int> m;
    for(int i=0; i<v.size(); i++){
        if(!m.count(v[i]))
            m[v[i]]=1;
        else
            m[v[i]]++;

        while (m.size()>b){
            m[v[left]]--;
            if(!m[v[left]])m.erase(v[left]);
            left++;
        }
        ans+=i-left+1;
    }
    return ans;
}
int solve(vector<int> v,int b){
    return atMostBelements(v,b)-atMostBelements(v,b-1);
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    int b;cin>>b;
    cout<<solve(v,b);
}