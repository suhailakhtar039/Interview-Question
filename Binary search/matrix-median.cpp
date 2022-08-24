#include<bits/stdc++.h>
using namespace std;
int noOfElements(vector<int> v,int ele){
    int ans=0;
    int st=0, en=v.size()-1;
    while (st<=en){
        int mid = st+(en-st)/2;
        if(v[mid]<ele){
            ans=mid+1;
            st=mid+1;
        }else
            en=mid-1;
    }
    return ans;
    
}
int solve(vector<vector<int>> v){
    int n=v.size(), m=v[0].size();
    int lo=0, hi=INT_MAX,ans;
    while (lo<=hi){
        int mid = lo+(hi-lo)/2;
        int cnt=0;
        for(int i=0; i<n; i++)
            cnt += noOfElements(v[i],mid);
        // if(cnt==n*m/2)return mid;
        if(cnt<=n*m/2)lo=mid+1,ans=mid;
        else hi = mid-1;
    }
    return ans;
    
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)cin>>v[i][j];
    cout<<solve(v);
    
}