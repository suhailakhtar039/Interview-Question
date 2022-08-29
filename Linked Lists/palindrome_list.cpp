// Author : Suhail Akhtar
// Date : 29-08-22
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
int solve(ListNode *head){
    ListNode *temp1=head;
    ListNode *rev = reverseList(temp1);
    printList(head);
    printList(rev);
    while(head && rev){
        if(head->val != rev->val)return 0;
        head=head->next;
        rev=rev->next;
    }
    return 1;
}
int main(){
    ListNode *head = createList();
    cout<<solve(head);
}