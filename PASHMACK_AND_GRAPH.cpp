#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
struct edge {
    int s,e,w;
    edge(int a,int b,int c) {
        s=a;e=b;w=c;
    }
};
bool cmp(edge a,edge b) {
    return a.w<b.w;
}
vector< vector<int> > v;
vector<int> dp,val;
vector<edge> edg;
using namespace std;
int main() {
    int a,b,c,n,m;
    scanf("%d%d",&n,&m);
    v.resize(n);
    dp.resize(n,0);
    val.resize(n,0);
    for(int i=0;i<m;i++) {
        scanf("%d%d%d",&a,&b,&c);a--;b--;
        edg.push_back(edge(a,b,c));
    }
    sort(edg.begin(),edg.end(),cmp);
    vector<int> pq;
    pq.push_back(0);
    int len=edg[0].w;
    for(int i=1;i<m;i++) {
        if(edg[i].w!=len) {
            pq.push_back(i);
            len=edg[i].w;
        }
    }
    vector<int> tmp(n,0);
    for(int i=0;i<pq.size();i++) {
        int j=((i==pq.size()-1)?m:pq[i+1]);
        //cout<<i<<" "<<j<<endl;
        for(int k=pq[i];k<j;k++) {
            a=edg[k].s;b=edg[k].e;
            tmp[b]=0;
        }
        for(int k=pq[i];k<j;k++) {
            a=edg[k].s;b=edg[k].e;
            tmp[b]=max(tmp[b],dp[a]+1);
        }
        for(int k=pq[i];k<j;k++) {
            a=edg[k].s;b=edg[k].e;
            dp[b]=max(dp[b],tmp[b]);
        }
        //for(int p:dp) cout<<p<<" ";cout<<endl;
    }
    cout<<*max_element(dp.begin(),dp.end());
    return 0;
}
