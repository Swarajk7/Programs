#include<bits/stdc++.h>
using namespace std;
struct node {
    int index;
    int rank[2];
};
int cmp(struct node a, struct node b)
{
    return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0):
               (a.rank[0] < b.rank[0] ?1: 0);
}
int *buildSuffixArray(char *txt,int n) {
    struct node *suff=new struct node[n];
    for(int i=0;i<n;i++) {
        suff[i].index=i;
        suff[i].rank[0]=txt[i]-'a';
        suff[i].rank[1]=(i+1<n)?txt[i+1]-'a':-1;
        cout<<i<<suff[i].rank[0]<<" "<<suff[i].rank[1]<<endl;
    }
    sort(suff,suff+n,cmp);
    int *ind=new int[n];
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
            int nextrank=(nextindex<n) ? suff[ind[nextindex]].rank[0] : -1;
            cout<<nextrank<<" "<<suff[i].index<<" "<<suff[i].rank[0]<<endl;
            suff[i].rank[1]=nextrank;
        }
        sort(suff,suff+n,cmp);
    }
    for(int i=0;i<n;i++) ind[i]=suff[i].index; //store ans in ind
    return ind;
}
int main() {
    char txt[]="baabaabaabaa";
    int *ar=buildSuffixArray(txt,strlen(txt));
    for(int i=0;i<strlen(txt);i++) {
        cout<<ar[i]<<" ";
    }
    return 0;
}
