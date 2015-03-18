#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
void in(TreeNode *root,TreeNode **f,TreeNode **m,TreeNode **l,TreeNode **prev) {
    if(!root) return;
    in(root->left,f,m,l,prev);
    if(*prev) {
        if(root->val < (*prev)->val) {
            if(*f) {
                *l=root;
            }
            else {
                *f=*prev;
                *m=root;
            }
        }
    }
    *prev=root;
    in(root->right,f,m,l,prev);
}
void recoverTree(TreeNode *root) {
        TreeNode *f=NULL,*m=NULL,*l=NULL,*p=NULL;
        in(root,&f,&m,&l,&p);
        if(!l) {
            l=m;
        }
        int t=f->val;
        f->val=l->val;
        l->val=t;
    }
TreeNode *f(TreeNode *root) {
        if(root==NULL) return NULL;
        if(!root->left && !root->right) return root;
        TreeNode *l=f(root->left);
        TreeNode *r=f(root->right);
        root->right=l;
        if(l) l->left=root;
        TreeNode *ptr=root;
        while(ptr->right!=NULL) ptr=ptr->right;
        ptr->right=r;
        if(r) r->left=ptr;
        root->left=NULL;
        return root;
    }
int main() {
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right=new TreeNode(5);
    root->right->right=new TreeNode(6);
    root=f(root);
    while(root!=NULL) {
        cout<<root->val<<" ";
        root=root->right;
    }
}
