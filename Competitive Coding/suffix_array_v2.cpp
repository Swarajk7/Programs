#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define MAXL 14
int P[MAXL][MAX];
struct node {
    int index;
    int rank[2];
};
bool cmp(node a,node b) {
    if(a.rank[0]==b.rank[0]) return a.rank[1]<b.rank[1];
    else return a.rank[0]<b.rank[0];
}
int buildSuffixArray(char *txt,int n) {
    struct node *suff=new struct node[n];
    for(int i=0;i<n;i++) {
        suff[i].index=i;
        suff[i].rank[0]=txt[i]-'a';
        suff[i].rank[1]=(i+1<n)?txt[i+1]-'a':-1;
    }
    sort(suff,suff+n,cmp);
    int *ind=new int[n];
    int cnt=0;
    for(int i=0;i<n;i++) P[cnt][i]=suff[i].index;
    cnt++;
    for(int k=4;k<2*n;k=k*2) {
        int rank=0;
        int prev_rank=suff[0].rank[0];
        suff[0].rank[0]=0;
        ind[suff[0].index]=0;
        for(int i=1;i<n;i++) {
            if(suff[i].rank[0]==prev_rank && suff[i].rank[1]==suff[i-1].rank[1]) suff[i].rank[0]=rank;
            else {
                rank++;
                prev_rank=suff[i].rank[0];
                suff[i].rank[0]=rank;
            }
            ind[suff[i].index]=i;
        }
        for(int i=0;i<n;i++) {
            int nextindex=suff[i].index+k/2;
            int nextrank=(nextindex<n) ?suff[ind[nextindex]].rank[0] : -1;
            suff[i].rank[1]=nextrank;
        }
        sort(suff,suff+n,cmp);
        for(int i=0;i<n;i++) P[cnt][i]=suff[i].index;
        cnt++;
    }
    int ans;
    for(int i=0;i<strlen(txt);i++) {
        if(P[cnt-1][i]<strlen(txt)/2) {
            ans=i;
            break;
        }
    }
    int ans1=P[cnt-1][ans];
    for(int i=ans+1;i<n;i++) {
        if(suff[P[cnt-1][i]].rank[0]==suff[ans1].rank[0]) {

        }
    }
}
char txt[2*MAX];
int getAns() {
    int cnt=buildSuffixArray(txt,strlen(txt));
    for(int i=0;i<strlen(txt);i++) {
        if(P[cnt-1][i]<strlen(txt)/2) {
            return P[cnt-1][i];
        }
    }
    return -1;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        string s;
        cin>>s;
        s=s+s;
        strcpy(txt,s.c_str());
        printf("%s\n",txt);
        printf("%d\n",getAns());
    }
    return 0;
}
