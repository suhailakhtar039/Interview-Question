// Author : Suhail Akhtar
// Date : 18-10-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> nums){
    int jmp=0,ans=0,prev=0,n=nums.size();
    if(n==1)return 0;
    if(nums[0]==0)return -1;
    for(int i=0;i<n-1;i++){
        jmp=max(jmp,i+nums[i]);
        if(i==prev)ans++,prev=jmp;
        // cout<<"i= "<<i<<" j= "<<jmp<<" ans= "<<ans<<" prev= "<<prev<<endl;
    }
    return ans;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v);
}