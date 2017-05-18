#include<bits/stdc++.h>
using namespace std;
int dp[10009];
long long rec(int i,int n) {
    if(i>=n) return 1;
    if(dp[i]!=-1) return dp[i];
    int ans=rec(i+1,n)+rec(i+2,n);
    dp[i]=ans;
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    memset(dp,-1,sizeof dp);
    printf("%lld\n",rec(0,n));
}
