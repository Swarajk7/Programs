#include<iostream>
#include<cstdio>
#include<vector>
#define MAX 300000
#define ll long long
using namespace std;
ll v[MAX];
int main()
{
    ll a;
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a);
        v[i]=a;
    }
    vector<ll> dp(n,0);
    dp[0]=(v[0]<=k)?v[0]:0;
    int l=0;
    ll mx=dp[0];
    for(int i=1;i<n;i++)
    {
        ll val=v[i]+dp[i-1];
        while(val>k && l<=i)
        {
            val-=v[l];
            l++;
        }
        if(l==i) dp[i]=0;
        else dp[i]=val;
        if(mx<dp[i]) mx=dp[i];
    }
    printf("%lld",mx);
    return 0;
}
