#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > v;
int par[1005];
int level[1005];
bool visited[1005];
int bfs(int root) {
    queue<int> q;
    int lvl=1;
    q.push(root);
    q.push(-1);
    level[root]=1;
    visited[root]=true;
    while(!q.empty()) {
        int x=q.front();q.pop();
        if(x==-1) {
            if(q.empty()) break;
            else {q.push(-1);lvl++;}
        } else {
            for(int i=0;i<v[x].size();i++) {
                int k=v[x][i];
                if(!visited[k]) {
                    visited[k]=true;
                    level[k]=lvl+1;
                    q.push(k);
                }
            }
        }
    }
    //for(int i=1;i<=v.size();i++) printf("%d %d\n",i,level[i]);
}
int main()
{
    int t,n,u,v1,q,k;
    scanf("%d",&t);
    int kk=1;
    while(t--) {
        printf("Case %d:\n",kk++);
        scanf("%d",&n);
        v.clear();
        v.resize(n+1);
        memset(par,-1,sizeof par);
        memset(visited,false,sizeof visited);
        memset(level,-1,sizeof level);
        for(int i=1;i<=n;i++) {
            scanf("%d",&k);
            for(int j=0;j<k;j++) {
                scanf("%d",&u);
                v[i].push_back(u);
                par[u]=i;
            }
        }
        int root=-1;
        for(int i=1;i<=n;i++) {
            if(par[i]==-1) {root=i;break;}
        }
        bfs(root);
        //printf("%d\n",root);
        scanf("%d",&q);
        while(q--) {
            scanf("%d%d",&u,&v1);
            int ans=-1;
            if(u==v1) ans=u;
            else {
                while(u!=v1) {
                    if(level[u]>=level[v1]) {
                        u=par[u];
                    } else v1=par[v1];
                }
                ans=u;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
