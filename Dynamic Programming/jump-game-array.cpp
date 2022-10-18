// Author : Suhail Akhtar
// Date : 18-10-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> v){
    int n = v.size();
    int last = n-1;
    for(int i=n-2; i>=0; i--){
        if(i+v[i]>=last)
            last=i;
    }
    return last==0;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v);
}