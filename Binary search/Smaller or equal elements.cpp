// Author: Suhail Akhtar
// Date  : 22-08-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &A, int B){
    int n=A.size();
    int first = 0, last = n-1;
    int ans =-1, mid;
    while(first<=last){
        mid = (first+last)/2;
        if(A[mid]<=B){
            ans = mid;
            first = mid+1;
        }else{
            last = mid-1;
        }
    }
    return ans==-1?0:ans+1;
}
int main(){
    int n;cin>>n;
    vector<int> v(n,0);
    for(int i=0; i<n; i++)cin>>v[i];
    int b;cin>>b;
    cout<<solve(v,b);
}