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
ListNode* solve(ListNode *head,int m,int n){
    ListNode *temp=head, *cur = head, *next=NULL, *prev=NULL;
    ListNode *first=temp, *second=temp->next;
    int cnt=0;
    while(temp){
        if(cnt==m-1){
            while (cnt!=n-1){
                next = temp->next;
                temp->next=prev;
                prev=temp;
                temp=next;
                cnt++;
            }
            next=temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            // cout<<"temp = "<<temp->val<<endl;
            // cout<<"prev = "<<prev->val<<endl;
            cout<<(first==head)<<endl;
            if(first==head && temp==NULL){
                cout<<"54\n";
                return prev;
            }else{
                cout<<"else\n";
                first->next = prev;
                second->next = temp;
            }

            break;
        }
        first=temp;
        second=temp->next;
        temp=temp->next;
        cnt++;
    }
    return head;
}
int main(){
    ListNode *head = createList();
    int m,n;cin>>m>>n;
    ListNode *temp = solve(head,m,n);
    printList(temp);
}