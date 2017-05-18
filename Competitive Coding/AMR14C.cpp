#include<bits/stdc++.h>
using namespace std;
#define N 100005
int ar[N];
int n;
int upper_boundC(int v) {
    int l=0;
    int r=n-1;
    int ans=0;
    while(l<=r) {
        int mid=(l+r)/2;
        if(ar[mid]<=v) {
            ans=mid+1;
            l=mid+1;
        } else r=mid-1;
    }
    return ans;
}
int lower_boundC(int v) {
    int l=0,r=n-1;
    int ans=-1;
    while(l<=r) {
        int mid=(l+r)/2;
        if(ar[mid]>=v) {
            ans=mid;
            r=mid-1;
        } else l=mid+1;
    }
    if(ans==-1) ans=n;
    return ans;
}
int main() {
    int t,m,x;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d",&n,&m,&x);
        for(int i=0;i<n;i++) {
            scanf("%d",&ar[i]);
            ar[i] %= m;
        }
        sort(ar,ar+n);
        //for(int i=0;i<n;i++) cout<<ar[i]<<" "; cout<<endl;
        long long ans=0;
        for(int i=0;i<n;i++) {
            int l=0-ar[i],r=x-ar[i];
            while(l<=ar[n-1]) {
               // cout<<l<<" "<<r<<" "<<m<<endl;
                int k1=(upper_boundC(r));
                int k2=(lower_boundC(l));
                //cout<<k1<<" "<<k2<<endl;
                ans+=k1-k2;
                r+=m;
                l+=m;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
