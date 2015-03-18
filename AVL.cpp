#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data,height;
    struct Node *left,*right;
    Node(int data) {
        this->data=data;
        left=NULL;
        right=NULL;
        height=0;
    }
};
int Height(Node *x) {
    if(x==NULL) return 0;
    else return x->height;
}
Node *LL(Node *x) {
    Node *y=x->left;
    x->left=y->right;
    y->right=x;
    x->height=max(1+Height(x->left),1+Height(x->right));
    y->height=max(1+Height(y->left),1+Height(x));
    return y;
}
Node *RR(Node *x) {
    Node *y=x->right;
    x->right=y->left;
    y->left=x;
    x->height=max(1+Height(x->left),1+Height(x->right));
    y->height=max(1+Height(y->right),1+Height(x));
    return y;
}
Node *LR(Node *x) {
    x->left=RR(x->left);
    return LL(x);
}
Node *RL(Node *x) {
    x->right=LL(x->right);
    return RR(x);
}
Node *InsertNode(Node *root,int data) {
    if(root==NULL) {
        root=new Node(data);
        //return root;
    } else if(root->data > data) {
        root->left=InsertNode(root->left,data);
        if(Height(root->left)-Height(root->right)==2) {
            if(data<root->left->data) root=LL(root);
            else root=LR(root);
        }
    } else if(root->data < data) {
        root->right=InsertNode(root->right,data);
        if(Height(root->right)-Height(root->left)==2) {
            if(data>root->right->data) root=RR(root);
            else root=RL(root);
        }
    }
    root->height=1+max(Height(root->left),Height(root->right));
    return root;
}
void InOrder(Node *x) {
    if(!x) return;
    InOrder(x->left);
    cout<<x->data<<" ";
    InOrder(x->right);
}
int main() {
    Node *head=NULL;
    //for(int i=1;i<=9;i++) head=InsertNode(head,i);
    head=InsertNode(head,1);
    head=InsertNode(head,4);
    head=InsertNode(head,3);
    head=InsertNode(head,2);
    head=InsertNode(head,9);
    head=InsertNode(head,8);
    head=InsertNode(head,6);
    head=InsertNode(head,7);
    assert(Height(head)==4);
    InOrder(head);
    return 0;
}
