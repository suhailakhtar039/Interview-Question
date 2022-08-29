// Author : Suhail Akhtar
// Date : 28-08-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> A,int B){
    // using map
    // unordered_map<int,int> m;
    // for(int i=0; i<A.size(); i++)m[A[i]]=i;
    // for(int i=0; i<A.size(); i++){
    //     if(m.count(A[i]+B) && m[A[i]+B]!=i)return 1;
    // }
    // return 0;
    // using two pointers
    sort(A.begin(),A.end());
    int i=0, j=1;
    while(i<A.size() && j<A.size() && i<=j){
        int diff=A[j]-A[i];
        if(diff==B)return 1;
        if(diff>B)i++;
        else j++;
    }
    return 0;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    int b;cin>>b;
    cout<<solve(v,b);
}