#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
#define ll long long
std::map<ll,ll> dp;
using namespace std;
ll ans(ll n) {
    //cout<<n<<endl;
    if(n>=(n/2+n/3+n/4)) return n;
    if(dp.find(n)!=dp.end()) return dp[n];
    ll ans1=ans(n/2)+ans(n/3)+ans(n/4);
    dp[n]=ans1;
    return ans1;
}
int main()
{
    ll n;
    while(scanf("%lld",&n)>=0) {
        dp.clear();
        printf("%lld\n",ans(n));
    }
    return 0;
}
