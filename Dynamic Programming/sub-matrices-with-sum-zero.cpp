// Author : Suhail Akhtar
// Date : 21-10-22
#include <bits/stdc++.h>
using namespace std;
int subarray_sum_k(vector<int> &nums , int target)
{
    int n=nums.size();
   
    unordered_map<int , int> mp;
   
    int count=0;
   
    mp[0]=1;
   
    long long sum=0;
   
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        if(mp.find( sum - target)!=mp.end())
        {
            count+=(mp[sum-target]);
        }
       
        mp[sum]++;
    }
   
    return count;
}
int solve(vector<vector<int>> mat){
    int  m=mat.size();
   
    if(m==0)
    {
        return 0;
    }
    int n=mat[0].size();
   
    long long res=0;
   
    for(int i=0;i<m;i++)
    {
         vector<int> nums(n , 0 );
        for(int j=i;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                nums[k]+=(mat[j][k]);
            }
           
            int ans = subarray_sum_k(nums , 0);
            res+=ans;
        }
    }
   
    return res;
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)cin>>v[i][j];
    cout<<solve(v);
}