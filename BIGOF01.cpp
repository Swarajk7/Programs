#include<bits/stdc++.h>
using namespace std;
//int ar[1000005];
vector<vector<int> > v;
vector<int> par;
void BFS(int s) {
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int r=q.front();
        q.pop();
        par[r]=s;
        for(int i=0;i<v[r].size();i++) {
            int qa=v[r][i];
            if(par[qa]==-1) q.push(qa);
        }
    }
}
int main() {
    int t,n,c,q,a,b;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&c);
        v.clear();
        par.clear();
        v.resize(n);
        par.resize(n,-1);
        while(c--) {
            scanf("%d%d",&a,&b);
            a--;b--;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int i=0;i<n;i++) if(par[i]==-1) BFS(i);
        scanf("%d",&q);
        while(q--) {
            scanf("%d%d",&a,&b);
            a--;b--;
            int x=par[a];
            int y=par[b];
            if(x!=y) {
                puts("No");
            } else puts("Yes");
        }
    }
    return 0;
}

/*void clearAr(int n) {
    for(int i=1;i<=n;i++) ar[i]=-1;
}
int root(int a) {
    if(ar[a]<0) return a;
    ar[a]=root(ar[a]);
    return ar[a];
}*/
