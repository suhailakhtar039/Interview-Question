// Author : Suhail Akhtar
// Date : 23-10-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> value,vector<int> weight,int totalWeight){
    int n = value.size();
    int ans[n+1][totalWeight+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=totalWeight; j++){
            if(i==0 || j==0)
                ans[i][j]=0;
            else if(weight[i-1]>j)
                ans[i][j]=ans[i-1][j];
            else
                ans[i][j]=max(ans[i-1][j],value[i-1]+ans[i-1][j-weight[i-1]]);
        }
    }
    return ans[n][totalWeight];
}
int main(){
    int n,totalWeight;cin>>n>>totalWeight;
    vector<int> v(n),w(n);
    for(int i=0; i<n; i++)cin>>v[i];
    for(int i=0; i<n; i++)cin>>w[i];
    cout<<solve(v,w,totalWeight);
}