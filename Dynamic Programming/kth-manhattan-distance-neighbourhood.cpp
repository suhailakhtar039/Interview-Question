// Author : Suhail Akhtar
// Date : 19-10-22
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> solve(vector<vector<int>> v,int k){
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> curMatrix = v,nextMetrix = v;
    while(k--){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int mx = curMatrix[i][j];
                mx = max(mx,i-1>=0?curMatrix[i-1][j]:-1);
                mx = max(mx,j-1>=0?curMatrix[i][j-1]:-1);
                mx = max(mx,i+1<n?curMatrix[i+1][j]:-1);
                mx = max(mx,j+1<m?curMatrix[i][j+1]:-1);
                nextMetrix[i][j]=mx;
            }
        }
        curMatrix = nextMetrix;
    }
    return curMatrix;
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin>>v[i][j];
    }
    int k;cin>>k;
    for(auto it:solve(v,k)){
        for(auto ij:it){
            cout<<ij<<" ";
        }
        cout<<endl;
    }
}