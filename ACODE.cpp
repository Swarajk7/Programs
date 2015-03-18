#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[5500];
ll dp[5500];
ll rec(int i,int N) {
    if(i>=N) return 1;
    ll ans=0;
    if(dp[i]!=-1) return dp[i];
    if(s[i]=='0') return 0;
    ans=rec(i+1,N);
    if(i!=N-1) {
        int z=(s[i]-48)*10+(s[i+1]-48);
        if(z>=1 && z<=26) ans+=rec(i+2,N);
    }
    dp[i]=ans;
    return ans;
}
int main()
{
    scanf("%s",s);
    while(strcmp(s,"0")!=0) {
        for(int i=0;i<=strlen(s)+2;i++) dp[i]=-1;
        cout<<rec(0,strlen(s))<<endl;
        scanf("%s",s);
    }
}
