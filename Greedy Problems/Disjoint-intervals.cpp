// Author : Suhail Akhtar
// Date : 24-10-22
#include <bits/stdc++.h>
using namespace std;
bool comp(vector<int> v1,vector<int> v2){
    int x1 = v1[0], y1 = v1[1], x2 = v2[0], y2 = v2[1];
    if(y1<y2)return true;
    return false;
}
int solve(vector<vector<int>> v){
    int n = v.size();
    if(!n)return n;
    int m = 2;
    sort(v.begin(),v.end(),comp);
    int ans = 1;
    int x = v[0][0], y = v[0][1];
    for(int i=1; i<n; i++){
        int x2 = v[i][0], y2 =v[i][1];
        if(x2>y){
            ans++;
            x=x2;
            y=y2;
        }
    }
    return ans;
}
int main(){
    int n;cin>>n;
    vector<vector<int>> v(n,vector<int>(2,0));
    for(int i=0; i<n; i++){
        cin>>v[i][0]>>v[i][1];
    }
    cout<<solve(v);
}