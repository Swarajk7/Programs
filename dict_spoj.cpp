#include<bits/stdc++.h>
using namespace std;
struct Node {
    bool flag;
    Node *ls[26];
    Node() {
        flag=false;
        for(int i=0;i<26;i++) ls[i]=NULL;
    }
};
class Trie {
    Node *T;
public:
    Trie() {
        T=new Node();
    }
    void ins(char *s,int sz) {
        ins_util(T,0,s,sz);
    }
    void ins_util(Node *,int ind,char *s,int sz);
    void dfs(Node *start,char *v,bool,int);
    bool Check(char *s,int sz) {
        Node *start=T;
        for(int i=0;i<sz;i++) {
            if(start->ls[s[i]-'a']==NULL) return false;
            else start=start->ls[s[i]-'a'];
        }
        char v[30];
        strcpy(v,s);
        dfs(start,v,false,sz);
        return true;
    }
};
void Trie :: dfs(Node *T,char *v,bool flag,int ind) {
    if(T->flag & flag) {
        printf("%s\n",v);
    }
    for(int i=0;i<26;i++) {
        if(T->ls[i]!=NULL) {
            v[ind]='a'+i;
            v[ind+1]='\0';
            dfs(T->ls[i],v,true,ind+1);
        }
    }
}
void Trie::ins_util(Node *T,int ind,char *s,int sz) {
    if(ind==sz) {
        T->flag=true;
        return;
    }
    int k=s[ind]-'a';
    if(T->ls[k]==NULL) {
        T->ls[k]=new Node();
        ins_util(T->ls[k],ind+1,s,sz);
    } else {
        ins_util(T->ls[k],ind+1,s,sz);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    string s;
    char s1[ 30 ];
    Trie t;
    while(n--) {
        scanf("%s",s1);
        t.ins(s1,strlen(s1));
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%s",s1);
        printf("Case #%d:\n",i);
        if(!t.Check(s1,strlen(s1))) {
            printf("No match.\n");
        }
    }
    return 0;

}
