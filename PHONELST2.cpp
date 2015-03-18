#include<bits/stdc++.h>
using namespace std;
struct Node {
    int value,prefix;
    bool flag;
    Node *ls[11];
    Node() {
        flag=false;
        value=-1;
        prefix=0;
        for(int i=0;i<10;i++) ls[i]=NULL;
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
    void ins_util(Node *,int ind,char *s,int);
    bool Check(char *s,int sz) {
        return check(T,s,0,sz);
    }
    bool check(Node *T,char * s,int ind,int);
};
void Trie::ins_util(Node *T,int ind,char *s,int sz) {
    if(ind==sz) {
        T->flag=true;
        return;
    }
    int k=s[ind]-'0';
    if(T->ls[k]==NULL) {
        T->ls[k]=new Node();
        ins_util(T->ls[k],ind+1,s,sz);
    } else {
        ins_util(T->ls[k],ind+1,s,sz);
    }
}
bool Trie :: check(Node *T,char *s,int ind,int sz) {
    if(ind==sz) {
        return true;
    }
    int k=s[ind]-48;
    //cout<<k<<"-"<<T->flag<<" ";
    if(T->flag) return false;
    if(T->ls[k]==NULL) return true;
    else {
        return check(T->ls[k],s,ind+1,sz);
    }
}
bool fun(string a,string b) {
    return a.length()<b.length();
}
int main()
{
    int tcases,n;
    cin>>tcases;
    char s[30];
    string ar[100002];
    Trie *T;
    while(tcases--) {
        T = new Trie();
        cin>>n;
        bool get=true;
        for(int i=0;i<n;i++) {
            scanf("%s",s);
            ar[i]=string(s);
        }
        sort(ar,ar+n,fun);
        for(int i=0;i<n;i++) {
            strcpy(s,ar[i].c_str());
            get = get & T->Check(s,strlen(s));
            //cout<<get<<endl;
            if(get) T->ins(s,strlen(s));
        }
        if(get) cout<<"YES\n";
        else cout<<"NO\n";
        delete T;
    }
    return 0;
}
