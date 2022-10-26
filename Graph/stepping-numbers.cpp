// Author : Suhail Akhtar
// Date : 26-10-22
#include <bits/stdc++.h>
using namespace std;
void bfs(vector<int> &v,int a,int b,int num){
    queue<int> q;
    unordered_map<int,bool> vis;
    q.push(num);
    vis[num]=true;
    while(q.size()){
        int step = q.front();q.pop();
        // cout<<"step = "<<step<<endl;
        if(step>=a && step<=b)
            v.push_back(step);
        if(step == 0 || step>b)continue;
        int s1 = step*10+step%10+1;
        int s2 = step*10+step%10-1;
        if(step%10==0){
            if(vis.count(s1)==0){
                q.push(s1);
                vis[s1]=true;
            }
        }else if(step%10==9){
            if(vis.count(s2)==0){
                q.push(s2);
                vis[s2]=true;
            }
        }else{
            if(vis.count(s1)==0){
                q.push(s1);
                vis[s1]=true;
            }
            if(vis.count(s2)==0){
                q.push(s2);
                vis[s2]=true;
            }
        }
    }
}
vector<int> solve(int a,int b){
    vector<int> ans;
    for(int i=0; i<10; i++)
        bfs(ans,a,b,i);
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    int a,b;cin>>a>>b;
    for(auto it:solve(a,b))
        cout<<it<<" ";
}