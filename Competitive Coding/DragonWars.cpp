#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > v;
vector<int> H;
void dfs(int i,int par,int x,int l,int r,bool flag,long long &ans) {
    if(i==x) {
        flag=true;
    }
    //cout<<i<<" f="<<flag<<endl;
    if(flag && H[i]>=l && H[i]<=r) ans++;
    for(int j=0;j<v[i].size();j++) {
        int k=v[i][j];
        if(k!=par) {
            dfs(k,i,x,l,r,flag,ans);
        }
    }
    if(i==x) flag=false;
}
int main() {
    int n,a,b,x,l,r;
    scanf("%d",&n);
    v.resize(n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a);
        H.push_back(a);
    }
    for(int i=0;i<n-1;i++) {
        scanf("%d%d",&a,&b);
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    scanf("%d",&q);
    while(q--) {
        scanf("%d%d%d",&x,&l,&r);
        long long ans=0;
        dfs(0,-1,x-1,l,r,false,ans);
        cout<<(ans*(ans-1)/2)<<endl;
    }
}
