// Author : Suhail Akhtar
// Date : 24-10-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> v){
    int n = v.size();
    // ans will store the total flips
    int ans = 0;
    for(int i=0; i<n; i++){
        // it depends on the parity of ans, if it is odd then some change will take place else no
        bool change = ans%2;
        
        if(change)v[i]=1-v[i];
        if(!v[i])ans++;
    }
    return ans;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v);
}