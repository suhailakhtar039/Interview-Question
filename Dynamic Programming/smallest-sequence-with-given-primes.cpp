// Author : Suhail Akhtar
// Date : 17-10-22
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(int a,int b,int c,int d){
    int i=0,j=0,k=0;
    vector<int> v(d+1,0);
    v[0]=1;
    for(int l=1; l<=d; l++){
        int c1 = a*v[i];
        int c2 = b*v[j];
        int c3 = c*v[k];
        int m = min(c1,min(c2,c3));
        if(m==c1)i++;
        if(m==c2)j++;
        if(m==c3) k++;
        v[l]=m;
    }
    v.erase(v.begin());
    return v;
}
int main(){
    int a,b,c,d;cin>>a>>b>>c>>d;
    vector<int> v = solve(a,b,c,d);
    for(auto i:v)cout<<i<<" ";
}