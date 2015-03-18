#include<iostream>
#include<cstdio>
using namespace std;
int dp[55][55];
int call(string s,int l,int r) {
    if(r==l) return 1;
    if(dp[l][r]!=0) return dp[l][r];
    int p;
    if(s[l]==s[r]) p = 1+call(s,l,r-1)+call(s,l+1,r);
    else p = call(s,l,r-1)+call(s,l+1,r);
    dp[l][r]=p;
}
int main()
{
    int t;
    string s;
    cin>>t;
    while(t--) {
        cin>>s;
        cout<<call(s,0,s.length()-1);
    }
    return 0;
}
