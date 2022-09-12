// Author : Suhail Akhtar
// Date : 12-09-22
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
ListNode* reverse(ListNode* node) {
    if(node->next == NULL) {
        return node;
    } else {
        ListNode* nNext = node->next;
        ListNode* rev = reverse(nNext);
        nNext->next = node;
        node->next = NULL;
        return rev;
    }
}

int size(ListNode* node) {
    if(node == NULL) return 0;
    return 1 + size(node->next);
}
ListNode* subtract(ListNode* A) {
    if(A->next == NULL) return A;
    ListNode* curr = A;
    // find half way point
    int n = size(A);
    int c = 0;
    while(curr != NULL && c<(n/2)) {
        curr = curr->next;
        c++;
    }

    ListNode* revcurr = reverse(curr);
    
    ListNode *i,*j;
    i = A;
    j = revcurr;
    while(i!= NULL && j!= NULL) {
        
         i->val = j->val - i->val;
         if(i->next == curr) break;
         i = i->next;
         j = j->next;    
    }

    revcurr = reverse(revcurr);

    return A;


}
int main(){
    ListNode *head = createList();
    printList(subtract(head));   
}