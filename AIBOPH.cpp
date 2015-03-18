#include<bits/stdc++.h>
using namespace std;
char s[7000],T[7000];
int dp[3][6105];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%s",s);
        int sz = strlen(s);
        char *x=strcpy(T,s);
        reverse(s,s+sz);
		for(int i=0;i<=sz;i++) dp[0][i]=0;
		for(int k=1;k<=sz;k++) {
            int i=k&1;
            dp[i][0]=0;
            for(int j=1;j<=sz;j++) {
                //cout<<s[k-1]<<" "<<T[j-1]<<endl;
                if(s[k-1]==T[j-1]) dp[i][j]=dp[1-i][j-1]+1;
                else dp[i][j]=max(dp[1-i][j], dp[i][j-1]);
            }
		}
		int ans=dp[sz&1][sz];
		printf("%d\n",sz-ans);
    }
    return 0;
}
