#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int w[2005],p[2005];
int rec(int i,int W,int n) {
    if(W<0) return -99999;
    if(i==n) {
        if(W>=0) return 0;
        else return -99999;
    }
    if(dp[i][W]!=-1) return dp[i][W];
    int k=max(rec(i+1,W,n),p[i]+rec(i+1,W-w[i],n));
    dp[i][W]=k;
    return k;
}
int main()
{
    int s,n;
    scanf("%d%d",&s,&n);
    for(int i=0;i<2005;i++) {
        for(int j=0;j<2005;j++) dp[i][j]=-1;
    }
    for(int i=0;i<n;i++) {
        scanf("%d%d",&w[i],&p[i]);
    }
    printf("%d",rec(0,s,n));
}
