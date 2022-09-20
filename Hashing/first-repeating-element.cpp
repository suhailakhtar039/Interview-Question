// Author : Suhail Akhtar
// Date : 20-09-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &v){
    int n=v.size();
    unordered_map<int,int> m;
    for(int i=0; i<n; i++){
        m[v[i]]+=1;
    }
    for(int i=0; i<n; i++){
        if(m[v[i]]>1)
            return v[i];
    }
    return -1;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v);
}