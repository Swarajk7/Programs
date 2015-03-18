#include<bits/stdc++.h>
using namespace std;
struct Node {
    int prefix;
    bool flag;
    Node *ls[2];
    Node() {
        flag=false;
        prefix=0;
        for(int i=0;i<2;i++) ls[i]=NULL;
    }
};
class Trie {
    Node *T;
public:
    Trie() {
        T=new Node();
    }
    void ins(int s) {
        ins_util(T,s,4);
    }
    void ins_util(Node *,int ,int );
    void maxAns(Node *,int y,int j,int &k);
    int mx(int n) {
        int ans=0;
        maxAns(T,n,4,ans);
        return ans;
    }
};
void Trie::ins_util(Node *T,int s,int j) {
    if(j==-1) {
        T->flag=true;
        return;
    }
    int k=1&(s>>j);
    //cout<<j<<" "<<k<<"\n";
    T->prefix++;
    if(T->ls[k]==NULL) {
        //cout<<"new\n";
        T->ls[k]=new Node();
        ins_util(T->ls[k],s,j-1);
    } else {
        ins_util(T->ls[k],s,j-1);
    }
}
void Trie::maxAns(Node *T,int y,int j,int &ans) {
    if(j==-1) {return;}
    int k=1&(y>>j);
    if(k==0) {
        if(T->ls[1]!=NULL) {  ans |= (1<<j); maxAns(T->ls[1],y,j-1,ans);}//fav
        else { ans &=~(1<<j); maxAns(T->ls[0],y,j-1,ans);} //unfav
    } else {
        if(T->ls[0]!=NULL) { ans |= (1<<j); maxAns(T->ls[0],y,j-1,ans); } //fav
        else { ans &=~(1<<j); maxAns(T->ls[1],y,j-1,ans);} //unfav
    }
}
int main()
{
    int t,n;
    scanf("%d",&t);
    Trie T;
    int res=INT_MIN;
    t--;
    scanf("%d",&n);
    T.ins(n);
    while(t--) {
        scanf("%d",&n);
        int ans=T.mx(n);
        //cout<<ans;
        res=max(res,ans);
        T.ins(n);
    }
    cout<<res<<endl;
    return 0;
}
