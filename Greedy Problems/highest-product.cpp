// Author : Suhail Akhtar
// Date : 23-10-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> v){
    int n = v.size();
    sort(v.begin(),v.end());
    return max(v[n-1]*v[n-2]*v[n-3],v[0]*v[1]*v[n-1]);
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v);
}