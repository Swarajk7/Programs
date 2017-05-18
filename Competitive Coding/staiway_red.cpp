#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll cost[505][505];
ll dp[505][505];
ll h[505],l[505];
#define INF 1000000000000
ll solve(int k,int m) {
    for(int i=0;i<=k;i++) dp[i][0]=0;
    for(int i=0;i<=k;i++) {
        for(int j=i+1;j<=k;j++) dp[i][j]=INF;
    }
    for(int i=1;i<=k;i++) dp[i][i]=0;
    for(int j=1;j<=k;j++) {
        for(int i=j+1;i<=k;i++) {

        }
    }
    for(int i=0;i<k;i++) {
            for(int j=0;j<k;j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
    return dp[k-1][m];
}
int main() {
    int t;
    scanf("%d",&t);
    ll m,k,w;
    while(t--) {
        scanf("%lld%lld%lld",&k,&m,&w);
        for(int i=0;i<k;i++) {
            scanf("%lld%lld",&l[i],&h[i]);
        }
        for(int i=0;i<k;i++) {
            for(int j=0;j<k;j++) {
                cost[i][j]=0;
                dp[i][j]=INF;
            }
        }
        for(int i=0;i<k;i++) {
            ll tl=l[i];
            for(int j=i+1;j<k;j++) {
                cost[i][j]=tl*h[j]+cost[i][j-1];
                tl+=l[j];
            }
        }
        for(int i=0;i<k;i++) {
            for(int j=0;j<k;j++) {
                cout<<cost[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<solve(k,m);
    }
    return 0;
}
