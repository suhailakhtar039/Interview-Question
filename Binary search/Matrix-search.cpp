// Author: Suhail Akhtar
// Date  : 22-08-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &A, int B){
    int n=A.size();
    int m=A[0].size();
    int first = 0, last = m-1;
    while(first<n and last>=0){
        if(B==A[first][last])
            return 1;
        else if(B<A[first][last])
            last--;
        else 
            first++;
    }
    return 0;
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>v[i][j];
    int b;cin>>b;
    cout<<solve(v,b);
}