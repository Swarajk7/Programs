#include <bits/stdc++.h>
using namespace std;
struct tnode {
    tnode *z,*o;
    //static int i;
    tnode() {
        z=NULL;
        o=NULL;
    }
};
//int tnode::i=1;
class Trie {
    tnode *root;
    int bit;
public:
    Trie() {
        root=new tnode();
        bit=31;
    }
    void Ins(int k) {
        ins(root,k,bit);
    }
    void ins(tnode *,int,int);
    void get(tnode *root,int val,int j,string &s);
     int getAns(int k) {
        string s="";
        get(root,k,bit,s);
        int ans=0;
        //cout<<s<<endl;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='1') ans = (ans<<1)|1;
            else ans= ans<<1;
        }
        return ans;
    }
};
void Trie :: ins(tnode *root,int val,int j) {
    if(j==-1) {
        return;
    } else {
        int k=(val>>j)&1;
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
void Trie:: get(tnode *root,int val,int j,string &s) {
    if(j==-1) return;
    int k=(val>>j)&1;
    if(k==0) {
        if(root->o!=NULL) {
            s.push_back('1');
            get(root->o,val,j-1,s);
        } else {
            s.push_back('0');
            get(root->z,val,j-1,s);
        }
    } else {
        if(root->z!=NULL) {
            s.push_back('1');
            get(root->z,val,j-1,s);
        } else {
            s.push_back('0');
            get(root->o,val,j-1,s);
        }
    }
}
int main()
{
    int tc,a;
    cin>>tc;
    Trie *t ;
    while(tc--) {
        int numberOfElements;
        cin>>numberOfElements;
        t=new Trie();
        int q=0;
        int ans=0;
        t->Ins(0);
        for(int i=0; i<numberOfElements;i++)
        {
            cin>>a;
            q=q^a;
            //cout<<q<<endl;
            ans=max(ans,t->getAns(q));
            t->Ins(q);
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}

