#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int ar[105][105],dp[105][105];
bool ok(int j,int m) {
    return j>=0 && j<m;
}
int max(int a,int b) {
    if(a>b) return a;
    else return b;
}
int rec(int i,int j,int n,int m) {
    if(i==n) return 0;
    int x=-999999;
    if(dp[i][j]!=-1) return dp[i][j];
    if(ok(j-1,m)) x=max(x,ar[i][j]+rec(i+1,j-1,n,m));
    if(ok(j+1,m)) x=max(x,ar[i][j]+rec(i+1,j+1,n,m));
    if(ok(j,m)) x=max(x,ar[i][j]+rec(i+1,j,n,m));
    dp[i][j]=x;
    return x;
}
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) scanf("%d",&ar[i][j]);
        }
        int ans=INT_MIN;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<m;i++) ans=max(ans,rec(0,i,n,m));
        printf("%d\n",ans);
    }
    return 0;
}
