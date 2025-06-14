#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
};

ListNode* deleteDuplicates(ListNode* head) {
    if(!head){return head;}
    ListNode *result = new ListNode{head->val,nullptr};
    ListNode *current1 = head->next, *current2 = result;
    int prev = head->val;
    while(current1 != nullptr){
        if(current1->val == prev){
            current1 = current1->next;
        }else{
            current2->next = new ListNode{current1->val,nullptr};
            current2 = current2->next;
            prev = current1->val;
            current1 = current1->next;
        }
    }
    return result;
}
int main(){
    int n; 
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter the nodes: ";
    int x; cin>>x;
    ListNode *head = new ListNode{x,nullptr};
    ListNode *tmp1 = head;
    for(int i=1; i<n; i++){
        int y; cin>>y;
        tmp1->next = new ListNode{y,nullptr};
        tmp1 = tmp1->next;
    }
    ListNode *curr = head;
    cout<<"The nodes are: ";
    while(curr != nullptr){
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    cout<<endl;
    ListNode *res = deleteDuplicates(head);
    cout<<"After removing the duplicates, nodes are: ";
    ListNode *t = res;
    while(t != nullptr){
        cout<<t->val<<" ";
        t = t->next;
    }
    cout<<endl;
    return 0;
}