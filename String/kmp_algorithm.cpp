// Author : Suhail Akhtar
// Date : 27-08-22
#include<bits/stdc++.h>
using namespace std;
void computeLPS(string pattern,vector<int> &lps){
    int m = pattern.length();
    int len = 0;
    int i = 1;
    while(i<m){
        cout<<"i= "<<i<<" len= "<<len<<endl;
        if(pattern[i]==pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len!=0)
                len=lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
        cout<<"i= "<<i<<" len= "<<len<<endl<<endl;
    }
}
int kmpAlgorithm(string haystack,string pattern){
    int n=haystack.length(),m=pattern.length();
    vector<int> lps(m,0);
    computeLPS(pattern,lps);
    cout<<"lps array= ";
    for(int i=0; i<lps.size(); i++){
        cout<<"["<<i<<"] : "<<lps[i]<<", ";
    }cout<<endl;
    int i=0,j=0;
    while(i<n){
        if(haystack[i]==pattern[j]){
            i++;j++;
        }else{
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
        if(j==m){
            cout<<i-j<<endl;
            j=lps[j-1];
        }
    }
}
int main(){
    string haystack,pattern;
    cin>>haystack>>pattern;
    kmpAlgorithm(haystack,pattern);
}