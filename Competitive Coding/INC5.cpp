#include<bits/stdc++.h>
using namespace std;
#define N 100005
int A[N];
void clearA(int n) {
    for(int i=1;i<=n;i++) A[i]=-1;
}
int root(int a) {
    if(A[a]<0) return a;
    A[a]=root(A[a]);
    return A[a];
}
void take_union(int a,int b) {
    int x=root(a),y=root(b);
    if(x!=y) {
        A[x]+=A[y];
        A[y]=x;
    }
}
int main() {
    int t,n,m,k,a,b;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d",&n,&m,&k);
        clearA(n);
        while(m--) {
            scanf("%d%d",&a,&b);
            take_union(a,b);
        }
        //for(int i=1;i<=3;i++) cout<<A[i]<<" "; cout<<endl;
        sort(A+1,A+n+1);
        int ans=0;
        for(int i=1;i<=n && k>0 && A[i]<0; i++,k--) {
            ans+=A[i];
        }
        printf("%d\n",-1*ans);
    }
    return 0;
}
