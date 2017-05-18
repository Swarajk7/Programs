#include<bits/stdc++.h>
using namespace std;
#define MAX 28
bool wendy[MAX];
vector<int> v[MAX];
int main() {
    int n,m,L,a;
    scanf("%d%d",&n,&L);
    for(int i=1;i<=n;i++) {
        v[i].resize(L);
        for(int j=0;j<L;j++) {
            scanf("%d",&a);
            v[i][j]=a;
        }
    }
    scanf("%d",&m);
    for(int i=1;i<=n;i++) wendy[i]=true;
    for(int i=0;i<m;i++) {
        scanf("%d",&a);
        wendy[a]=false;
    }
    int ans=0,l=0;
    bool found[MAX];
    for(int ii=1;ii<=n;ii++) found[ii]=false;
    for(int i=0;i<L;i++) {
        bool flag=false;
        for(int j=1;j<=n;j++) {
            if(wendy[j]) {
                if(v[j][i]==1) {
                    l=i+1;
                    for(int ii=1;ii<=n;ii++) found[ii]=false;
                    flag=true;
                    break;
                }
            }
        }
        if(flag) continue;
        for(int j=1;j<=n;j++) {
            if(!wendy[j])
            {
                if(v[j][i]==1) found[j]=true;
                int cnt=0;
                for(int ii=1;ii<=n;ii++) if(found[ii]==true) cnt++;
                if(cnt==m) ans=max(ans,i+1-l);
            }
        }
    }
    cout<<ans<<endl;
}
