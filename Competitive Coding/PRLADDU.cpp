#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int ar[MAX];
int main() {
    int t,n;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&ar[i]);
        int d=0,v=0;
        long long ans=0;
        do {
            while(d<n && ar[d]>=0) d++;
            while(v<n && ar[v]<=0) v++;
            if(!(d<n && v<n)) break;
            int z=min(ar[d]*-1,ar[v]);
            //cout<<d<<" "<<v<<" "<<z<<endl;
            ar[d]+=z;
            ar[v]-=z;
            ans=ans+abs(d-v)*z;
        } while(d<n && v<n);
        printf("%lld\n",ans);
    }
    return 0;
}
