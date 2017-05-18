#include<bits/stdc++.h>
using namespace std;
int ar[25][25];
#define N 20
long long int dp[N][1<<N];
long long int rec(int s,int mask,int n) {
    if(s==n) {
        if(mask == (1<<n)-1) {
            return 1;
        } else return 0;
    }
    if(dp[s][mask]!=-1) return dp[s][mask];
    long long int ans=0;
    for(int j=0;j<n;j++) {
        if(ar[s][j]==1 && (mask&(1<<j))==0) {
            int c=mask | (1<<j);
            ans += rec(s+1,c,n);
        }
    }
    dp[s][mask]=ans;
    return ans;
}
void clearDP(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<(1<<n);j++) dp[i][j]=-1;
    }
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        clearDP(n);
        for(int i=0;i<n;i++) {
            for(  int j=0;j<n;j++) scanf("%d",&ar[i][j]);
        }
        cout<<rec(0,0,n)<<endl;
    }
    return 0;
}
