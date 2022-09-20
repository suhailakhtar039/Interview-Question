// Author : Suhail Akhtar
// Date : 20-09-22
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> solve(vector<int> &nums,int target){
    int n=nums.size();
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++){
                int k=j+1,l=n-1;
                while(k<l){
                    long long int sum=(nums[i]*1ll+nums[j]*1ll+nums[k]*1ll+nums[l]*1ll);
                    if(sum==target){
                        vector<int> four={nums[i],nums[j],nums[k],nums[l]};
                        v.push_back(four);
                        while(k<n and nums[k]==four[2])k++;
                        while(l>=0 and nums[l]==four[3])l--;
                    }
                    else if(sum>target)l--;
                    else k++;
                }
                while(j+1<n and nums[j]==nums[j+1])j++;
            }
        }
        return v;
}
int main(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    vector<vector<int>> ans = solve(v,k);
    for(auto it:ans){
        for(auto ij:it){
            cout<<ij<<" ";
        }cout<<endl;
    }
}