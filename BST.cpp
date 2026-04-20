#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(){}
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST{
private:
    Node* root;
    void in_private(Node*& r, int val){
        if(r == NULL){
            r = new Node(val);
        }else if(val < r->data){
            in_private(r->left,val);
        }else if(val > r->data){
            in_private(r->right,val);
        }
    }
    void inorder_private(Node*& r){
        if(r==NULL){
            return;
        }
        inorder_private(r->left);;
        cout<<r->data<<" ";
        inorder_private(r->right);
    }
    Node* search_private(Node* r, int key){
        while(r != NULL){
            if(r->data == key){
                return r;
            }else if(key < r->data){
                r = r->left;
            }else if(key > r->data){
                r = r->right;
            }
        }
        return NULL;
    }
    void delete_private(Node*& r, int key){
        Node* parent = NULL;
        Node* child = r;
        while(child && child->data != key){
            parent = child;
            if(key < child->data){
                child = child->left;
            }else{
                child = child->right;
            }
        }

        if(child==NULL){
            cout<<"Key Not Found\n";
            return;
        }

        if(!child->left && !child->right){
            if(!parent){
                r = NULL;
            }else if(parent->left==child){
                parent->left = NULL;
            }else if(parent->right==child){
                parent->right = NULL;
            }
            delete child;
        }else if(!child->left || !child->right){
            Node* grand;
            if(child->left){
                grand = child->left;
            }else{
                grand = child->right;
            }

            if(!parent){
                r = grand;
            }else if(parent->left==child){
                parent->left = grand;
            }else if(parent->right==child){
                parent->right = grand;
            }
            delete child;
        }else{
            Node* succesorparent = child;
            Node* succesor = child->right;

            while(succesor->left){
                succesorparent = succesor;
                succesor = succesor->left;
            }
            child->data = succesor->data;
            if(succesorparent->left==succesor){
                succesorparent->left = succesor->right;
            }else if(succesorparent->right==succesor){
                succesorparent->right = succesor->right;
            }
            delete succesor;
        }
    }
public:
    BST(){
        root = NULL;
    }

    void insert(int val){
        in_private(root,val);
    }
    void inorder(){
        if(root==NULL){
            cout<<"No elements\n";
            return;
        }
        inorder_private(root);
        cout<<"\n";
    }
    void search(int key){
        Node* tmp = search_private(root,key);
        if(tmp==NULL){
            cout<<"NOT FOUND!!\n";
        }else{
            cout<<"Foundd!!\n";
        }
    }
    void del(int key){
        delete_private(root,key);
    }


};

int main(){
    BST t;
    t.inorder();
    vector<int> v = {5,8,1,4,2,0,3};
    for(int i : v){
        t.insert(i);
    }
    t.inorder();
    t.search(40);
    t.search(0);
    t.search(8);

    t.del(5);
    t.inorder();

    return 0;
}