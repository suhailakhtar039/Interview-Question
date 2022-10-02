// Author : Suhail Akhtar
// Date : 02-10-22
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
struct DecidePriority{
    public:
    bool operator()(ListNode* a,ListNode *b){
        return a->val > b->val;
    }
};
ListNode* solve(vector<ListNode*> v){
    int n = v.size();
    priority_queue<ListNode*,vector<ListNode*>,DecidePriority> pq;
    for(int i=0; i<n; i++){
        ListNode *head = v[i];
        pq.push(head);
    }
    ListNode *head, *temp;
    bool isFirst = true;
    while(!pq.empty()){
        ListNode* got = pq.top();pq.pop();
        if(isFirst){
            head = new ListNode(got->val);
            temp = head;
            isFirst=false;
        }else{
            temp->next = got;
            temp = temp->next;
        }
        // cout<<" got = "<<got->val<<endl;
        if(got->next!=NULL){
            pq.push(got->next);
        }
    }
    return head;
}
int main(){
    int n;cin>>n;
    vector<ListNode*> v(n);
    for(int i=0; i<n; i++){
        v[i] = createList();
    }
    ListNode* ans = solve(v);
    printList(ans);   
}