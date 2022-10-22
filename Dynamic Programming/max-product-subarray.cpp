// Author : Suhail Akhtar
// Date : 22-10-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> v){
    int n = v.size();
    int mx = v[0];
    int imax = mx, imin = mx;
    for(int i=1; i<n; i++){
        if(v[i]<0)
            swap(imax,imin);
        
        imax = max(v[i],v[i]*imax);
        imin = min(v[i],v[i]*imin);

        mx = max(mx,imax);
    }
    return mx;
}
int main(){
    int n; cin>>n; 
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cout<<solve(v);
}