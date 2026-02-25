#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

};

class Link{
public:
    Node *head;
    Link(){
        head = NULL;
    }

    void insert_at_first(int val){
        if(head==NULL){
            Node* dum = new Node;
            dum->data = val;
            dum->next = NULL;
            head = dum;
            return;
        }
        Node* temp = new Node(); 
        temp->data = val;
        temp->next = head;
        head = temp;

    }

    void insert_at_last(int val){
        Node *tmp = new Node();
        tmp = head;
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        Node *dd = new Node();
        dd->data = val;
        dd->next = NULL;
        tmp->next = dd;
    }

    void insert_at_middle_r(int val, int target){
        Node* first = new Node();
        first = head;
        Node* second = new Node();
        second = head->next;

        while(second != NULL && first->data != target){
            first = first->next;
            second = second->next;

        }
        Node* tmp = new Node();
        tmp->data = val;
        first->next = tmp;
        tmp->next = second;
    }

    void insert_at_middle_l(int val, int target){
        Node* first = new Node();
        first = head;
        Node* second = new Node();
        second = head->next;

        while(second != NULL && second->data != target){
            first = first->next;
            second = second->next;

        }
        Node* tmp = new Node();
        tmp->data = val;
        first->next = tmp;
        tmp->next = second;
    }

    void del_first(){
        head = head->next;
    }
    void del_last(){
        Node* tmp = new Node();
        tmp = head;
        while(tmp->next->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = NULL;

    }

    void del_mid(int target){
        Node* first = new Node();
        first = head;
        Node* second = new Node();
        second = head->next;

        while(second != NULL && second->data != target){
            first = first->next;
            second = second->next;
        }
        first->next = second->next;
    }

    void print(){
        Node* tmp;
        tmp = head;
        while(tmp != NULL){
            cout<<tmp->data<<"  ";
            tmp = tmp->next;
        }
        cout<<endl;
    }
};

int main(){
    Link l1;
    l1.insert_at_first(20);
    l1.print();
    l1.insert_at_first(10);
    l1.insert_at_first(5);
    l1.insert_at_first(3);
    l1.print();
    l1.insert_at_last(30);
    l1.insert_at_last(50);
    l1.print();
    l1.insert_at_middle_r(15,10);
    l1.print();
    l1.insert_at_middle_r(40,30);
    l1.print();
    l1.insert_at_middle_l(2,5);
    l1.print();
    l1.insert_at_middle_l(45,50);
    l1.print();
    l1.del_first();
    l1.print();
    l1.del_last();
    l1.print();
    l1.del_mid(20);
    l1.print();
    return 0;
}
