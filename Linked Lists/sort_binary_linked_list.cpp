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
ListNode* solve(ListNode *head){
    int cnt0=0;
    ListNode *temp=head;
    while(temp){
        if(temp->val==0)cnt0++;
        temp=temp->next;
    }
    temp=head;
    while(temp){
        if(cnt0){
            temp->val=0;
            cnt0--;
        }
        else if(cnt0==0)
            temp->val=1;
        temp=temp->next;
    }
    return head;
}
int main(){
    ListNode *head = createList();
    cout<<solve(head);
}