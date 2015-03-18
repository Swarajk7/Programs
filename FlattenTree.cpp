#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode *flatten(TreeNode *root) {
        TreeNode *head=NULL;
        helper(root,&head);
        root=head;
        return head;
    }
    void helper(TreeNode *root,TreeNode **head) {
        if(root==NULL) return;
        static TreeNode *prev=NULL;
        helper(root->left,head);
        if(prev==NULL) {
            *head=root;
        } else {
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        helper(root->right,head);
    }
};
void pre(TreeNode *h) {
    if(!h) return;
    cout<<h->val<<" ";
    pre(h->left);
    pre(h->right);
}
int main() {
    TreeNode *head=NULL;
    head=new TreeNode(1);
    head->left=new TreeNode(2);
    Solution s;
    head=s.flatten(head);
    pre(head);
    return 0;
}
