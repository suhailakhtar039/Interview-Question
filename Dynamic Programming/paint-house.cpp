// Author : Suhail Akhtar
// Date : 17-10-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> v){
    int n = v.size();
    int minCost[3]={v[0][0],v[0][1],v[0][2]};
    for(int i=1; i<n; i++){
        int r = v[i][0]+min(minCost[1],minCost[2]);
        int g = v[i][1]+min(minCost[0],minCost[2]);
        int b = v[i][2]+min(minCost[0],minCost[1]);

        minCost[0]=r;
        minCost[1]=g;
        minCost[2]=b;
    }
    return *min_element(minCost,minCost+3);
}
int main(){
    int n;cin>>n;
    vector<vector<int>> v(n,vector<int>(3,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++)
            cin>>v[i][j];
    }
    cout<<solve(v);
}