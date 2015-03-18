#include<bits/stdc++.h>
using namespace std;
#define MAX 20
int ar[MAX][MAX];
#define DP_MAX 1<<MAX
int dp[DP_MAX][20];
#define INF 1<<20
#define FOR(x,n) for(int x=0;x<n;x++)
int n,kk;
int G(int S,int i)
{
    if(S==0) return ar[i][0];
    if(dp[S][i]!=-1) return dp[S][i];
    //cout<<S<<" "<<i<<endl;
    dp[S][i]=INF;
    for(int j=0;j<n;j++)
    {
        if(j!=i &&(S & (1<<j)))
        {
            dp[S][i]=min(dp[S][i],G(S&(~(1<<j)),j)+ar[i][j]);
        }
    }
    return dp[S][i];
}
int main()
{
    cin>>n>>kk;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
                cin>>ar[i][j];
                if(ar[i][j]==-1) ar[i][j]=INF;
                if(i==j) ar[i][j]=0;
        }
    }
    FOR(k,n) {
        FOR(i,n) {
            FOR(j,n) {
                ar[i][j]=min(ar[i][j],ar[i][k]+ar[k][j]);
            }
        }
    }
    //FOR(i,n) {FOR(j,n) { cout<<ar[i][j]<<" ";} cout<<endl;}
    int S=1<<n;S-=2;
    for(int i=0;i<(1<<n);i++) {
        for(int j=0;j<n;j++) dp[i][j]=-1;
    }
    G(S,0);
    int ans=dp[S][0];
    //cout<<ans<<endl;
    if(ans<=kk) { cout<<"YES!\n"; cout<<ans; }
    else cout<<"NO!";
    return 0;
}
