#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct edge {
    int s,d,w;
    edge(int a,int b,int c) {
        s=a;
        d=b;
        w=c;
    }
};
vector<edge> v;
vector<int> uf;
int root(int a) {
    if(uf[a]==-1) return a;
    else {
        uf[a]=root(uf[a]);
        return uf[a];
    }
}
bool cmp(edge a,edge b) {
    return a.w<b.w;
}
int main() {
    int t,a,b,w,n,h;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&h);
        v.clear();uf.clear();uf.resize(n,-1);
        while(h--) {
            scanf("%d%d%d",&a,&b,&w);
            a--;b--;
            v.push_back(edge(a,b,w));
        }
        sort(v.begin(),v.end(),cmp);
        int ans=0;
        for(int i=0;i<v.size();i++) {
            a=root(v[i].s);
            b=root(v[i].d);
            if(a==b) continue;
            else {
                uf[a]=b;
                ans+=v[i].w;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
