// Author : Suhail Akhtar
// Date : 30-08-22
#include<bits/stdc++.h>
using namespace std;
class ListNode{
  public:
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
void printList(ListNode *head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }cout<<endl;
}
ListNode* createList(){
    ListNode *head,*temp;
    bool first = true;
    while(1){
        int x;cin>>x;
        if(x==-1)break;
        if(first){
            head=new ListNode(x);
            temp=head;
            first=false;
        }else{
            ListNode *node = new ListNode(x);
            temp->next = node;
            temp=temp->next;
        }
    }
    return head;
}
ListNode* reverseList(ListNode* head){
    ListNode *temp=head,*prev=NULL,*nxt;
    while(temp){
        nxt=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nxt;
    }
    return prev;
}
int solve(ListNode *head,int b){
    vector<int> v;
    while(head){
        v.push_back(head->val);
        head=head->next;
    }
    int n=v.size();
    int mid = n/2;
    if(mid-b>=0)
        return v[mid-b];
    else
     return -1;
}
int main(){
    ListNode *head = createList();
    int b;cin>>b;
    cout<<solve(head,b);
}