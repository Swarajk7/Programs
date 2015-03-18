#include<bits/stdc++.h>
using namespace std;
char s1[2005],s2[2005];
int s1_length,s2_length;
int dp[2005][2005];
int editDist(int i,int j) {
    for(int i=0;i<=s1_length;i++) dp[i][0]=i;
    for(int j=0;j<=s2_length;j++) dp[0][j]=j;
    for(int i=1;i<=s1_length;i++) {
        for(int j=1;j<=s2_length;j++) {
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
            else {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
                dp[i][j]=min(dp[i-1][j-1],dp[i][j]);
                dp[i][j]++;
            }
        }
    }
    return dp[s1_length][s2_length];
}
void clearDP() {
    for(int i=0;i<=s1_length;i++) {
        for(int j=0;j<=s2_length;j++) dp[i][j]=-1;
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        scanf("%s%s",s1,s2);
        s1_length=strlen(s1);
        s2_length=strlen(s2);
        clearDP();
        cout<<editDist(0,0)<<endl;
    }
    return 0;
}
