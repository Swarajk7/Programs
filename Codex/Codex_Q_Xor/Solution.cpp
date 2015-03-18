#include<bits/stdc++.h>
using namespace std;
int ar[10005];
struct tnode {
    tnode *z,*o;
    int pre;
    static int i;
    tnode() {
        //cout<<"new"<<i++<<endl;
        z=NULL;
        o=NULL;
        pre=0;
    }
};
int tnode::i=1;
class Trie {
    tnode *root;
    int bit;
    void ins(tnode *,int,int);
    void get(tnode *root,int val,int j,int &s);
    tnode* del(tnode *root,int val,int j);
public:
    Trie() {
        root=new tnode();
        bit=31;
    }
    void Ins(int k) {
        ins(root,k,bit);
    }
    int getAns(int k) {
        int ans=0;
        get(root,k,bit,ans);
        return ans;
    }
    void Del(int k) {
        root = del(root,k,bit);
        //cout<<"z";
    }
    void Pre() {pre(root);}
    void pre(tnode *);
};
tnode * Trie :: del(tnode *root,int val,int j) {
    if(j==-1) {
        if(root->pre==1) {
            free(root);
            return NULL;
        }
        root->pre--;
        return root;
    }
    int k=(val>>j)&1;
    //cout<<j<<" "<<k<<root->pre<<endl;
    if(k==0) root->z=del(root->z,val,j-1);
    else root->o=del(root->o,val,j-1);
    if(root->pre==1) {
        free(root);
        return NULL;
    }
    root->pre--;
    return root;
}
void Trie :: pre(tnode *x) {
    if(!x) return;
    cout<<x->pre<< " ";
    pre(x->z);
    pre(x->o);
}
int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    Trie t;
    for(int i=0;i<n;i++) {
        scanf("%d",&ar[i]);
        t.Ins(ar[i]);
    }
    int c;
    int x,y;
    while(q--) {
        cin>>c;
        if(c==0) {
            cin>>x>>y;
            t.Del(ar[x]);
            ar[x]=y;
            t.Ins(y);
        } else {
            cin>>x;
            cout<<t.getAns(x)<<endl;
        }
    }
    return 0;
}
void Trie :: ins(tnode *root,int val,int j) {
    if(j==-1) {
        root->pre++;
        return;
    } else {
        int k=(val>>j)&1;
        root->pre++;
        if(k==0) {
            if(root->z==NULL) {
                root->z=new tnode();
            }
            ins(root->z,val,j-1);
        } else {
            if(root->o==NULL) {
                root->o=new tnode();
            }
            ins(root->o,val,j-1);
        }
    }
}
void Trie:: get(tnode *root,int val,int j,int &s) {
    if(j==-1) return;
    int k=(val>>j)&1;
    //cout<<root->pre<<endl;
    if(k==0) {
        if(root->o!=NULL) {
            s=(s<<1)|1;
            get(root->o,val,j-1,s);
        } else {
            s=s<<1;
            get(root->z,val,j-1,s);
        }
    } else {
        if(root->z!=NULL) {
            s=(s<<1)|1;
            get(root->z,val,j-1,s);
        } else {
            s=s<<1;
            get(root->o,val,j-1,s);
        }
    }
}
