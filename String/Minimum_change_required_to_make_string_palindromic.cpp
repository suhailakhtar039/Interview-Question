// Author: Suhail Akhtar
// Date  : 26-08-22
#include <bits/stdc++.h>
using namespace std;
int solve(string str){
    int n = str.length();
    int left = 0;
    int right = n - 1;
    int added = 0;
    while (left < right) {
        // if left and right characters are same increase
        // left and decrease right pointer
        cout<<"left = "<<left<<" right= "<<right<<" added= "<<added<<endl;
        if (str[left] == str[right]) {
            left++;
            right--;
        }
        // else think of adding some characters at front and
        // start comparing the elements again
        else {
            left = 0;
            added = n - right;
            while (str[left] == str[right]) {
                added--;
                left++;
            }
            right--;
        }
        cout<<"left = "<<left<<" right= "<<right<<" added= "<<added<<endl;
    }
    return added;
}
int main(){
    string s;cin>>s;
    cout<<solve(s);
}