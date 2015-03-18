#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,k;
ll dp[16][1<<16][16];
ll rec(int k1,int prev,int mask) {
    //cout<<prev<<mask<<endl;
    if(k1==n) return 1;
    if(dp[k1][mask][prev]!=-1) return dp[k1][mask][prev];
    ll ans=0;
    for(int i=1;i<=n;i++) {
            //cout<<(mask&(1<<(i-1)))<<"-";
        if((mask&(1<<(i-1)))==0) {
            if(abs(i-prev)<=k) ans+=rec(k1+1,i,(mask|(1<<(i-1))));
        }
    }
    dp[k1][mask][prev]=ans;
    return ans;
}
void clearDP() {
    for(int k=0;k<16;k++) {
        for(int i=0;i<(1<<n);i++) {
            for(int j=0;j<n;j++) dp[k][i][j]=-1;
        }
    }
}
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>k;
        ll ans=0;
        clearDP();
        for(int i=1;i<=n;i++) {
            ans+=rec(0,i,1<<(i-1));
        }
        cout<<ans<<endl;
    }
    return 0;
}
