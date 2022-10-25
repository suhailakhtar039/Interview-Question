// Author : Suhail Akhtar
// Date : 25-10-22
#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> v,int k){
    int n = v.size();
    unordered_map<int,int> m;
    for(int i=0; i<n; i++)m[v[i]]=i;
    int initialIndex = 0, largestValue = n;
    for(int i=0;initialIndex<n && i<k; i++){
        int indexOfHighest = m[largestValue];
        if(v[initialIndex]==v[indexOfHighest]){
            largestValue--;
            initialIndex++;
            i--;    
            continue;
        }
        m[v[initialIndex]] = indexOfHighest;
        swap(v[initialIndex],v[indexOfHighest]);
        largestValue--;
        initialIndex++;
    }
    return v;
}
int main(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    for(auto i:solve(v,k))
        cout<<i<<" ";
}