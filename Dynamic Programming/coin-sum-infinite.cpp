// Author : Suhail Akhtar
// Date : 22-10-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> v,int k){
    int n = v.size();
    int tab[k+1]={0};
    tab[0]=1;
    for(int i=0; i<n; i++){
        for(int j=v[i]; j<=k; j++){
            tab[j]=(tab[j]%1000007+tab[j-v[i]]%1000007)%1000007;
        }
    }
    return tab[k];
}
int main(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v,k);
}