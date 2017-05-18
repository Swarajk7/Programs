#include<bits/stdc++.h>
using namespace std;
int num[1005][1005];
bool visited[1005*1005];
bool visit[1005][1005];
vector<int> dp;
map<int, pair<int,int> > mp;
bool ok(int i,int j,int n) {
    return i>=0 && i<n && j>=0 && j<n;
}
int dfs(int x,int y,int n) {
    visited[num[x][y]]=true;
    if(ok(x+1,y,n)) {
        if(num[x+1][y]==1+num[x][y]) return 1+dfs(x+1,y,n);
    }
    if(ok(x-1,y,n)) {
        if(num[x-1][y]==1+num[x][y]) return 1+dfs(x-1,y,n);
    }
    if(ok(x,y-1,n)) {
        if(num[x][y-1]==1+num[x][y]) return 1+dfs(x,y-1,n);
    }
    if(ok(x,y+1,n)) {
        if(num[x][y+1]==1+num[x][y]) return 1+dfs(x,y+1,n);
    }
    return 1;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int t1=1;t1<=t;t1++) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                scanf("%d",&num[i][j]);
                mp[num[i][j]] = make_pair(i,j);
                visited[num[i][j]]=false;
                visit[i][j]=false;
            }
        }
        int ans=-1;
        int anspos=-1;
        for(int i=1;i<=n*n;i++) {
            if(!visited[i]) {
                pair<int,int> p= mp[i];
                int k=dfs(p.first,p.second,n);
                if(ans<k) {
                    ans=k;
                    anspos=i;
                }
            }
        }
        cout<<"Case #"<<t1<<": "<<anspos<<" "<<ans<<endl;
    }
}
