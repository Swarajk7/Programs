#include<bits/stdc++.h>
using namespace std;
char s[2005];
int dp[2005][2005];
bool check() {
    for(int i=0;i<strlen(s);i++) if(s[i]!='-') return true;
    return false;
}
int rec(int i,int l,int r,int n) {
    if(i==n) {
        if(l==r) return 0;
        else return 99999;
    }
    if(r>l) return 99999;
    int k;
    if(dp[i][l]!=-1) return dp[i][l];
    if(s[i]=='{') {
        k=min(rec(i+1,l+1,r,n),1+rec(i+1,l,r+1,n));
    } else {
        k=min(1+rec(i+1,l+1,r,n),rec(i+1,l,r+1,n));
    }
    dp[i][l]=k;
    return k;
}
void setArray(int len) {
    for(int i=0;i<len+3;i++) {
        for(int j=0;j<len+3;j++) dp[i][j]=-1;
    }
}
int main()
{
    scanf("%s",s);
    int cnt=1;
    while(check()) {
        setArray(strlen(s));
        printf("%d. %d\n",cnt,rec(0,0,0,strlen(s)));
        cnt++;
        scanf("%s",s);
    }
    return 0;
}
