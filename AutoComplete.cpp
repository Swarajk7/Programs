#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    bool isfinal;
    int prefix;
    TreeNode *child[27];
    TreeNode() {
        isfinal=0;
        prefix=0;
        for(int i=0;i<27;i++) child[i]=NULL;
    }
};
char c[1000005];
TreeNode *insertNode(TreeNode *head,int n,int &ans) {
    bool flag=false;
    int z=1;
    ans=0;
    TreeNode *x=head;
    for(int index=0;index<n;index++) {
        //cout<<(char)c[index];
        int p=c[index]-'a';
        ans+=z;
        //cout<<head->child[p]<<" ";
        if(head->child[p]==NULL) {
            head->child[p]=new TreeNode();
            z=0;
        }
        head=head->child[p];
    }
    //cout<<endl;
    return x;
}
void deleteNodes(TreeNode *head) {
    if(head!=NULL) {
        for(int i=0;i<26;i++) {
            if(head->child[i]) deleteNodes(head->child[i]);
        }
        free(head);
    }
}
int main() {
    int t,n;
    scanf("%d",&t);
    for(int t1=1;t1<=t;t1++) {
        TreeNode *head=new TreeNode();
        scanf("%d",&n);
        long long cum_ans=0;
        for(int i=0;i<n;i++) {
            int ans=0;
            scanf("%s",c);
            head = insertNode(head,strlen(c),ans);
            cum_ans+=ans;
        }
        printf("Case #%d: %I64d\n",t1,cum_ans);
        deleteNodes(head);
    }
    return 0;
}
