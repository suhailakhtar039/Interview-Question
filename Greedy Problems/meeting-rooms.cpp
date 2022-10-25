// Author : Suhail Akhtar
// Date : 25-10-22
#include <bits/stdc++.h>
using namespace std;
bool compare( vector<int> &a , vector<int> &b)
{
    return a[0] < b[0];
}
int solve(vector<vector<int>> nums){
    sort(nums.begin() , nums.end() , compare);
   
    int n=nums.size();
   
    priority_queue< int , vector<int> , greater<int> > pq;
   
    int ans=1;
   
    pq.push(nums[0][1]);
   
   
    for(int i=1;i<n;i++)
    {
        if(nums[i][0] >= pq.top())
        {
            pq.pop();
            pq.push(nums[i][1]);
        }
        else
        {
            pq.push(nums[i][1]);
        }
    }
   
    return pq.size();
}
int main(){
    int n;cin>>n;
    vector<vector<int>> v(n,vector<int>(2,0));
    for(int i=0; i<n; i++)cin>>v[i][0]>>v[i][1];
    cout<<solve(v);
}