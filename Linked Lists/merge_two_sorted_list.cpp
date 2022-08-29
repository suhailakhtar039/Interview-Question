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
ListNode* solve(ListNode *head1, ListNode *head2){
    if(head1==NULL && head2==NULL)return NULL;
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;
    ListNode *ans = new ListNode(-1);
    if(head1->val<head2->val){
        ans->val = head1->val;
        ans->next = solve(head1->next,head2);
    }else{
        ans->val = head2->val;
        ans->next = solve(head1,head2->next);
    }
    return ans;
}
int main(){
    ListNode *head1 = createList();
    ListNode *head2 = createList();
    ListNode *ans = solve(head1,head2);
    printList(ans);
}