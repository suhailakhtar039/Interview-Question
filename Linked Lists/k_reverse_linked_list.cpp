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
ListNode* solve(ListNode *head,int k){
    if(!head)return NULL;
    int cnt = 0;
    ListNode *cur = head, *prev = NULL, *next = NULL;
    while(cur && cnt<k){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        cnt++;
    }
    // cout<<"head = "<<head->val<<endl;
    // cout<<"next = "<<next->val<<endl;
    // cout<<"prev = "<<prev->val<<endl;
    if(next)
        head->next = solve(next,k);
    return prev;
}
int main(){
    ListNode *head = createList();
    int k;cin>>k;
    ListNode *temp = solve(head,k);
    printList(temp);
}