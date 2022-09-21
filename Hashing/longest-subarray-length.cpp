// Author : Suhail Akhtar
// Date : 21-09-22
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &v){
    int n = v.size();
    unordered_map<int,int> m;
    int sum=0,mxLen=0;
    for(int i=0; i<n; i++){
        sum+=v[i]==0?-1:1;
        if(sum==1){
            mxLen=i+1;
        }else if(m.count(sum)==0){
            m[sum]=i;
        }

        if(m.count(sum-1)){
            mxLen=max(mxLen,i-m[sum-1]);
        }
    }
    return mxLen;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v);
}