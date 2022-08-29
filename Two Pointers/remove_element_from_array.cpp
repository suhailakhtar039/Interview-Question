// Author : Suhail Akhtar
// Date : 29-08-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &A,int B){
    int n=A.size();
    int i=0,j=0,cnt=0;
    for(int i=0; i<n; i++){
        if(A[i]!=B){
            cnt++;
            swap(A[i],A[j]);
            j++;
        }
    }
    return cnt;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    int b;cin>>b;
    cout<<solve(v,b)<<endl;
    for(int i:v)cout<<i<<" ";
}