// Author : Suhail Akhtar
// Date : 31-08-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> v){
    int n=v.size();
    if(n<=2)return 0;
    stack<int> leftToRight,rightToLeft;
    leftToRight.push(0);
    rightToLeft.push(n-1);
    int pre[n]={0},suf[n]={0};
    pre[0]=suf[n-1]=0;
    leftToRight.push(0);
    rightToLeft.push(n-1);
    for(int i=1; i<n; i++){
        int ele = v[i];
        while(!leftToRight.empty() && ele>=v[leftToRight.top()])leftToRight.pop();
        int val = leftToRight.empty()?0:leftToRight.top();
        pre[i] = val;
        leftToRight.push(i);
    }

    for(int i=n-2; i>=0; i--){
        int ele = v[i];
        while(!rightToLeft.empty() && ele>=v[rightToLeft.top()])rightToLeft.pop();
        int val = rightToLeft.empty()?0:rightToLeft.top();
        suf[i] = val;
        rightToLeft.push(i);
    }
    long long ans = 0;
    long long mod = 1e9+7;
    for(int i = 0; i < n; i++){
        long long int mul = (pre[i]*suf[i]);
        ans = max(ans*1ll,mul%mod)%mod;
    }
    return ans%mod;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v);
}