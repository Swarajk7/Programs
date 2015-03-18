#include<stdio.h>
#define ll long long
ll A[205];
int par[205];
int Root(int p) {
    if(par[p]==-1) return p;
    else {
        par[p]=Root(p);
        return par[p];
    }
}
int Union(int i,int j) {
    //printf("%d %d\n",i,j);
    if(Root(i)==Root(j)) return;
    int x=Root(i),y=Root(j);
    printf("%d %d\n",x,y);
    par[y]=x;
}
ll gcd(ll a,ll b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main() {
    int i,j,t,n;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(i=0;i<n;i++) {
            scanf("%lld",&A[i]);
            par[i]=-1;
        }
        for(i=0;i<n;i++) {
            for(j=i+1;j<n;j++) {
                ll k=gcd(A[i],A[j]);
                //printf("%lld %lld %lld\n",A[i],A[j],k);
                if(k>1) Union(i,j);
                //for(i=0;i<n;i++) printf("%d ",par[i]); printf("\n");
            }
        }
        for(i=0;i<n;i++) printf("%d ",par[i]);
    }
    return 0;
}
