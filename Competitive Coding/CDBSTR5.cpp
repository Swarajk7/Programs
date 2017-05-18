#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > v;
#define pb push_back
int dfs(int node,int par,int &ans) {
    int max1=0,max2=0;
    for(int i=0;i<v[node].size();i++) {
        if(v[node][i]!=par) {
            int got=dfs(v[node][i],node,ans);
            if(got>=max1) { max2=max1; max1=got;}
            else if(got>=max2) { max2=got;}
        }
    }
    ans=max(ans,max1+max2);
    return max1+1;
}
int main() {
    int t,u,v1,n;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        v.clear();
        v.resize(n);
        for(int i=0;i<n-1;i++) {
            scanf("%d%d",&u,&v1);
            u--;
            v1--;
            v[u].pb(v1);
            v[v1].pb(u);
        }
        int ans=0;
        dfs(0,-1,ans);
        printf("%d\n",ans);
    }
    return 0;
}
