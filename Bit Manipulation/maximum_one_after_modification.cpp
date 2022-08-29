// Author : Suhail Akhtar
// Date : 29-08-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> v,int b){
    int n=v.size();
    int cnt=0,ans=0,l=0;
    for(int i=0; i<n; i++){
        if(v[i]==0)cnt++;
        while(cnt>b){
            if(v[l]==0)cnt--;
            l++;
        }
        ans=max(ans,i-l+1);
    }
    return ans;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    int b;cin>>b;
    cout<<solve(v,b);
}