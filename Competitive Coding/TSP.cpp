#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
vector< vector<int> > v,dp;
int n;
int G(int S,int i)
{
    if(S==0) return v[i][0];
    if(dp[S][i]!=-1) return dp[S][i];
    cout<<S<<" "<<i<<endl;
    dp[S][i]=INT_MAX;
    for(int j=0;j<n;j++)
    {
        if(j!=i &&(S & (1<<j)))
        {
            dp[S][i]=min(dp[S][i],G(S&(~(1<<j)),j)+v[i][j]);
        }
    }
    return dp[S][i];
}
int main()
{
    scanf("%d",&n);
    v.resize(n,vector<int>(n));
    dp.resize(1+(1<<n),vector<int>(n,-1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>v[i][j];
    }
    int S=1<<n;S-=2;
    G(S,0);
    for(int i=0;i<dp.size();i++)
    {
        for(int j=0;j<dp[i].size();j++) cout<<dp[i][j]<<" ";cout<<endl;
    }
    cout<<dp[S][0]<<endl;
    return 0;
}
