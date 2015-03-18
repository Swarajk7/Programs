#include<bits/stdc++.h>
using namespace std;
int w[205],h[205];
int dp[605][605];
int n;
int waste(int W,int H) {
    //cout<<W<<" "<<H<<endl;
    if (W<=0 || H<=0) return 0;
    int ans=W*H;
    if(dp[W][H]!=-1) return dp[W][H];
    for(int i=0;i<n;i++) {
        if(W>=w[i] && H>=h[i]) {
            ans=min(ans,waste(W,H-h[i])+waste(W-w[i],h[i]));
            ans=min(ans,waste(w[i],H-h[i])+waste(W-w[i],H));
        }
    }
    //cout<<W<<" "<<H<<" "<<ans<<endl;
    dp[W][H]=ans;
    return ans;
}
int main()
{
    int t,W,H;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&W,&H);
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d%d",&w[i],&h[i]);
        }
        for(int i=0;i<605;i++) {
            for(int j=0;j<605;j++) dp[i][j]=-1;
        }
        printf("%d\n",waste(W,H));
    }
    return 0;
}
