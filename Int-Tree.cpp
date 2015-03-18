#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
vector< vector<int> > tr;
vector<bool> visit;
vector<int> dp;
int dfs(int i) {
    if(visit[i]) return 0;
    visit[i]=true;
    int dia=0,max1=0,max2=0;
    for(int j=0;j<tr[i].size();j++) {
        if(!visit[tr[i][j]]) {
            int val=dfs(tr[i][j]);
            if(val>max1) {
                max2=max1;
                max1=val;
            }
            else if(val>max2) {
                max2=val;
            }
        }
    }
    dia=max1+max2;
    dp[i]=dia;
    for(int j=0;j<tr[i].size();j++) {
        dp[i]=max(dp[i],dp[tr[i][j]]);
    }
    //cout<<i<<" "<<max1<<" "<<max2<<" "<<dp[i]<<endl;
    return max1+1;
}
int main() {
    int n,u,v,r,q,s;
    scanf("%d",&n);
    tr.resize(n);
    dp.resize(n,-1);
    for(int i=0;i<n-1;i++) {
        scanf("%d%d",&u,&v);
        u--;v--;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    visit.resize(n);
    scanf("%d",&r);r--;
    dfs(r);
    //for(int i=0;i<n;i++) cout<<dp[i]<<" ";
    scanf("%d",&q);
    while(q--) {
        scanf("%d",&u);
        u--;
        printf("%d\n",dp[u]);
    }
    cout<<endl;
}
