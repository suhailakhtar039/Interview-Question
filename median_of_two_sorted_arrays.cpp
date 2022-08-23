// Author: Suhail Akhtar
// Date  : 23-08-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> A,vector<int> B){
    int n=A.size(), m=B.size();
    if(m<n)
     return solve(B,A);
    if(n==0 && m==1){
        return B[0];
    }
    cout<<"n= "<<n<<" m= "<<m<<endl;
    int sze=(n+m+1)/2;
    int lo=0, hi=n;
    int cut1,cut2;
    bool even=(n+m)%2==0;
    while(lo<=hi){
        cut1=(lo+hi)/2;
        int left1Size = cut1;
        int left2Size = sze-cut1;

        int left1 = left1Size>0?A[left1Size-1]:INT_MIN;
        int left2 = left2Size>0?B[left2Size-1]:INT_MIN;

        int right1 = left1Size<n?A[left1Size]:INT_MAX;
        int right2 = left2Size<m?B[left2Size]:INT_MAX;

        if(left1<=right2 && left2<=right1){
            if(even){
                return (max(left1,left2)+min(right1,right2))/2.0;
            }else{
                return max(left1,left2);
            }
        }
        else if(left1>right2)
            hi=cut1-1;
        else
            lo=cut1+1;
    }
    return -1;
}
int main(){
    int n,m;cin>>n>>m;
    vector<int> v1(n),v2(m);
    for(int i=0; i<n; i++)cin>>v1[i];
    for(int i=0; i<m; i++)cin>>v2[i];
    cout<<solve(v1,v2);
}