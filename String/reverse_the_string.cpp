// Author : Suhail Akhtar
// Date : 28-08-22
#include<bits/stdc++.h>
using namespace std;
void reverseString(string &s){
    int i=0;
    for(int i=0; i<s.length()/2; i++){
        swap(s[i],s[s.length()-i-1]);
    }
}
string solve(string s){
    string withoutSpaces="";
    string temp="";
    string ans="";
    int i=0;
    while(s[i]==' ')i++;
    for(; i<s.length(); i++){
        if(s[i]!=' '){
            temp+=s[i];
        }else{
            if(temp.length()!=0){
                withoutSpaces+=temp;
                withoutSpaces+=' ';
                temp="";
            }
        }
    }
    if(temp.length()){
        withoutSpaces+=temp;
    }
    // cout<<"withoutSpaces = "<<withoutSpaces<<endl;
    if(withoutSpaces.back()==' ')
        withoutSpaces = withoutSpaces.substr(0,withoutSpaces.length()-1);
    // cout<<"without spaces = "<<withoutSpaces<<endl;
    reverseString(withoutSpaces);
    // cout<<"reversed string = "<<withoutSpaces<<endl;
    temp = "";
    for(int i=0; i<withoutSpaces.length(); i++){
        if(withoutSpaces[i]!=' ')
            temp+=withoutSpaces[i];
        else{
            reverseString(temp);
            ans+=temp+" ";
            temp="";
        }
    }
    if(temp.length()!=0){
        reverseString(temp);
        ans+=temp;
    }
    return ans;
}
int main(){
    string s;
    getline(cin,s);
    cout<<s<<endl;
    cout<<solve(s);
}