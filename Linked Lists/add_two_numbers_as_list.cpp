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
ListNode* solve(ListNode *A,ListNode *B){
    ListNode *ans=new ListNode(-1), *temp1 = A, *temp2 = B, *temp3;
    bool first = true;
    temp3=ans;
    int car = 0;
    while (temp1 && temp2){
        int sum = (temp1->val+temp2->val+car);
        car = sum/10;
        ListNode *node = new ListNode(sum%10);
        temp3->next = node;
        temp1 = temp1->next;
        temp2 = temp2->next;
        temp3 = temp3->next;
    }
    while(temp1){
        int sum = (temp1->val+car);
        car = sum/10;
        ListNode *node = new ListNode(sum%10);
        temp3->next = node;
        temp1 = temp1->next;
        temp3 = temp3->next;
    }
    while(temp2){
        int sum = (temp2->val+car);
        car = sum/10;
        ListNode *node = new ListNode(sum%10);
        temp3->next = node;
        temp2 = temp2->next;
        temp3 = temp3->next;
    }
    if(car){
        ListNode *node = new ListNode(car);
        temp3->next = node;
    }
    return ans->next;
    
}
int main(){
    ListNode *head = createList();
    ListNode *head1 = createList();
    
    ListNode *sum = solve(head,head1);
    printList(sum);
}