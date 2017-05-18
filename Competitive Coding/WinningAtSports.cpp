#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
#define MOD 1000000007
long long Sfree(int a,int b) {
    if(a<=b) return 0;
    if(dp[a][b]!=-1) return dp[a][b];
    long long ans;
    if(b==0) ans = 1;
    else ans = (Sfree(a-1,b)+Sfree(a,b-1))%MOD;
    dp[a][b]=ans;
    return ans;
}
void clearDP() {
    for(int i=0;i<2005;i++) {
        for(int j=0;j<2005;j++) dp[i][j]=-1;
    }
}
long long Sfull(int a,int b,int maxa,int maxb) {
    long long ans=0;
    if(a>maxa) return 0;
    if(b>maxb) return 0;
    if(dp[a][b]!=-1) return dp[a][b];
    if(a>b) {
        if(b==maxb) return 1;
        else return 0;
    }
    else {
        ans = (Sfull(a+1,b,maxa,maxb) + Sfull(a,b+1,maxa,maxb))%MOD;
    }
    dp[a][b]=ans;
    return ans;
}
int main() {
    int t,a,b;
    scanf("%d",&t);
    int t1=1;
    while(t--) {
        scanf("%d-%d",&a,&b);
        clearDP();
        long long ans=Sfree(a,b);
        clearDP();
        long long ans1=Sfull(0,0,a,b);
        printf("Case #%d: %I64d %I64d\n",t1++,ans,ans1);
    }
    return 0;
}
