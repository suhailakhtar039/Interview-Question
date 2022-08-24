// Author: Suhail Akhtar
// Date  : 22-08-22
#include <bits/stdc++.h>
using namespace std;
int solve(int x,int n,int d){
        if(x==0)return 0;
        if(n==0){
            return 1;
        }
        long y;
        if (n % 2 == 0) {
            y = solve(x, n / 2, d);
            y = (y * y) % d;
        }
    
        // If B is odd
        else {
            y = x % d;
            y = (y * solve(x, n - 1, d) % d) % d;
        }
    
        return (int)((y + d) % d);
}
int main(){
    int x,n,d;cin>>x>>n>>d;
    cout<<solve(x,n,d);

}