#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int dp[1805][305][11];
ll rec(int r,int b,int l) {
    if(l<0 || r<0) return 0;
    if(b==0) {
        return r==0;
    }
    //cout<<r<<" "<<b<<" "<<l<<endl;
    if(dp[r][b][l]!=-1) return dp[r][b][l];
    ll ans = (rec(r-6,b-1,l)+rec(r-4,b-1,l)+rec(r,b-1,l)+rec(r,b-1,l-1))%MOD;
    dp[r][b][l]=ans;
    return ans;
}
void clearDP(int r,int b,int l) {
    for(int i=0;i<=r;i++) {
        for(int j=0;j<=b;j++) {
            for(int k=0;k<=l;k++) dp[i][j][k]=-1;
        }
    }
}
ll fact[305];
ll pow(int a, int b)
{
    ll x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x * y);
            if (x > MOD)
                x %= MOD;
        }
        y = (y * y);
        if (y > MOD)
            y %= MOD;
        b /= 2;
    }
    return x;
}

ll modInverse(ll a)
{
    return pow(a, MOD- 2);
}
ll proc(int x,int y,int z,int p,int b) {
    ll xx=(fact[x]*fact[y])%MOD;
    xx=(xx*fact[z])%MOD;
    xx=(xx*fact[p])%MOD;
    ll up=fact[b];
    cout<<up<<" "<<modInverse(xx)<<endl;
    return (up*modInverse(xx))%MOD;
}
ll it(int r,int b,int l) {
    int r6=0,r4=0;
    ll ans=0;
    for(int i=0;i<=b;i++) {
        r6=i*6;
        r4=r-r6;

        if(r4>=0 && r4%4==0) {
            r4/=4;
            if(r4+i<=b)
            for(int k=0;k<=l;k++) ans+=proc(i,r4,k,b-(i+r4+k),b);
        }
    }
    return ans;
}
int main() {
    int t,r,b,l;
    scanf("%d",&t);
    fact[0]=1;
    for(int i=1;i<=304;i++) fact[i]=(i*fact[i-1])%MOD;
    //for(int i=1;i<=10;i++) cout<<fact[i]<<endl;
    while(t--) {
        scanf("%d%d%d",&r,&b,&l);
        ll ans;
        if(r>6*b) ans=0;
        else {
            ans=it(r,b,l);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
