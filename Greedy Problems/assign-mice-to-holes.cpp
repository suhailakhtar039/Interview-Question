// Author : Suhail Akhtar
// Date : 25-10-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> v1,vector<int> v2){
    int n = v1.size();
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int ans = INT_MIN;
    for(int i=0; i<n; i++)
        ans = max(ans,abs(v1[i]-v2[i]));
    return ans;
}
int main(){
    int n;cin>>n;
    vector<int> v1(n), v2(n);
    for(int i=0; i<n; i++)cin>>v1[i];
    for(int i=0; i<n; i++)cin>>v2[i];
    cout<<solve(v1,v2);
}