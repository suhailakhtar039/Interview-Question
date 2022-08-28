// Author : Suhail Akhtar
// Date : 28-08-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> A){
    int ans = 0;
    for(auto it:A)
        ans^=it;
    return ans;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v);
}