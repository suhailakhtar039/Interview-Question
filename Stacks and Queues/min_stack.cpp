// Author : Suhail Akhtar
// Date : 31-08-22
#include<bits/stdc++.h>
using namespace std;
class MinStack{
    stack<int> s;
    int minEle;
    public:
    void push(int x){
        if(s.size()==0){
            s.push(x);
            minEle = x;
            return;
        }
        if(x<minEle){
            s.push(2*x-minEle);
            minEle = x;
        }else{
            s.push(x);
        }
    }

    void pop(){
        if(!s.size())return;
        int topEle = s.top();
        if(topEle<minEle)
            minEle = 2*minEle-topEle;
        s.pop();
    }

    int top(){
        if(!s.size())return -1;
        int topEle = s.top();
        if(topEle<minEle)
            return minEle;
        return topEle;
    }

    int getMin(){
        if(!s.size())return -1;
        return minEle;
    }
};
int main(){
    return 0;
}