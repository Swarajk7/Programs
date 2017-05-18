#include<bits/stdc++.h>
using namespace std;
int L[20],D[20];
int dp[20][1<<20];
int solve(int n,int ind,int S,int tans) {
    if(ind==n) return 0;
    if(dp[ind][S]!=-1) return dp[ind][S];
    int ans=INT_MIN;
    for(int i=0;i<n;i++) {
        if((S&(1<<i))==0) {
            int k=S|(1<<i);
            int dec=D[i]*i*ind;
            cout<<i<<" "<<dec<<" "<<ind<<" "<<tans<<endl;
            ans=max(ans,tans-dec+solve(n,ind+1,k,tans-dec));
        }
    }
    dp[ind][S]=ans;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>L[i];
    for(int i=0;i<n;i++) cin>>D[i];
    int sum=accumulate(L,L+n,0);
    //cout<<sum<<endl;
    for(int i=0;i<20;i++) {
        for(int j=0;j<(1<<18);j++) dp[i][j]=-1;
    }
    cout<<solve(n,0,0,sum);
    return 0;
}
