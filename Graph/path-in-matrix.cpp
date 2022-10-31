// Author : Suhail Akhtar
// Date : 31-10-22
#include <bits/stdc++.h>
using namespace std;
int goX[]={-1,+1,0,0};
int goY[]={0,0,-1,+1};
bool isSafe(vector<vector<int>> &mat,int x,int y,int n){
    return x>=0 && x<n && y>=0 && y<n && (mat[x][y]==3 || mat[x][y]==2);
}
void dfs(vector<vector<int>> &mat,vector<vector<bool>> &vis,bool &path,int srx,int sry){
    if(vis[srx][sry])return;
    // cout<<"srx = "<<srx<<" sry = "<<sry<<endl;
    vis[srx][sry] = true;
    if(mat[srx][sry]==2){
        path = true;
        return;
    }
    for(int i=0; i<4; i++){
        int dex = srx+goX[i];
        int dey = sry+goY[i];
        if(isSafe(mat,dex,dey,mat.size()) && !vis[dex][dey]){
            dfs(mat,vis,path,dex,dey);
        }
    }
}
int solve(vector<vector<int>> &mat){
    int n = mat.size();
    int srx=-1,sry=-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j]==1){
                srx = i;
                sry = j;
                break;
            }
        }
    }
    bool path = false;
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    dfs(mat,vis,path,srx,sry);
    return path;
}
int main(){
    int n;cin>>n;
    vector<vector<int>> v(n,vector<int>(n,0));
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)cin>>v[i][j];
    cout<<solve(v);    
}