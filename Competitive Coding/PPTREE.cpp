#include<bits/stdc++.h>
using namespace std;
vector < pair<int,int> > G[100005];
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
    void get(tnode *root,int val,int j,int &s);
     int getAns(int k) {
        int ans=0;
        get(root,k,bit,ans);
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
void Trie:: get(tnode *root,int val,int j,int &s) {
    if(j==-1) return;
    int k=(val>>j)&1;
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
Trie *T;
vector<bool> visited;
vector<int> S;
void dfs(int u,int par,int xorval){
  S.push_back(xorval);
  for(int i=0;i<G[u].size();i++)
    if(G[u][i].first != par)
        dfs(G[u][i].first,u,xorval xor G[u][i].second);
}
int main()
{
    int t,n,u,v,w;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        S.clear();
        for(int i=0;i<n-1;i++){
            scanf("%d %d %d",&u,&v,&w);
            u--,v--;
            G[u].push_back(make_pair(v,w));
            G[v].push_back(make_pair(u,w));
        }
        T=new Trie();
        dfs(0,-1,0);
        int mx=0;
        T->Ins(0);
        for(int i=0;i<S.size();i++) {
            mx=max(mx,T->getAns(S[i]));
            T->Ins(S[i]);
        }
        printf("%d\n",mx);
        for(int i=0;i<=n;i++)
            G[i].clear();
        delete T;
    }
    return 0;
}
