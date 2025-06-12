#include<bits/stdc++.h>
using namespace std;
 
struct Node{
    int data; 
    Node *next;
};

int main(){
    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();

    first->data = 10; second->data = 20; third->data = 30;
    first->next = second; second->next = third; third->next = nullptr;

    Node *tmp = first;
    cout<<"Elements of 1st linked list: ";
    while(tmp != nullptr){
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl;

    Node *v1 = new Node();
    Node *v2 = new Node();
    Node *v3 = new Node();

    v1->data = 100; v1->next = v2;
    v2->data = 200; v2->next = v3;
    v3->data = 300; v3->next = nullptr;

    Node *curr = v1;
    cout<<"Elements of the 2nd linked list: ";
    while(curr != nullptr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
    Node *merge = new Node{first->data,nullptr};
    Node *current1 = first->next;
    Node *current2 = merge;

    while(current1 != nullptr){
        current2->next = new Node{current1->data,nullptr};
        current2 = current2->next;
        current1 = current1->next;
    }
    current1 = v1;
    while(current1 != nullptr){
        current2->next = new Node{current1->data,nullptr};
        current2 = current2->next;
        current1 = current1->next;
    }

    Node *tera = merge;
    cout<<"Merged two list: ";
    while(tera != nullptr){
        cout<<tera->data<<" ";
        tera = tera->next;
    }
    cout<<endl;
    return 0;
    }