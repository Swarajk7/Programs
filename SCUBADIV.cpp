#include<bits/stdc++.h>
using namespace std;
int o[1005],n[1005],w[1005];
int dp[100][200][1005];
int ox,ni;
int rec(int i,int ox_t,int ni_t,int N) {
    if(ox_t>=ox && ni_t>=ni) return 0;
    if(i==N) {
        if(ox_t>=ox && ni_t>=ni) return 0;
        else return 99999;
    }
    if(dp[ox_t][ni_t][i]!=-1) return dp[ox_t][ni_t][i];
    int k=min(rec(i+1,ox_t,ni_t,N),w[i]+rec(i+1,min(ox_t+o[i],ox),min(ni_t+n[i],ni),N));
    dp[ox_t][ni_t][i]=k;
    return k;
}
void clr() {
    for(int i=0;i<100;i++) {
        for(int j=0;j<200;j++) {
            for(int k=0;k<1005;k++) dp[i][j][k]=-1;
        }
    }
}
int main()
{
    int t,N;
    scanf("%d",&t);
    while(t--) {
        clr();
        scanf("%d%d",&ox,&ni);
        scanf("%d",&N);
        for(int i=0;i<N;i++) {
            scanf("%d%d%d",&o[i],&n[i],&w[i]);
        }
        printf("%d\n",rec(0,0,0,N));
    }
}
