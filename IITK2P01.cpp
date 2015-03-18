#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n,k;
    int t;
    scanf("%d",&t);
    //cout<<(long long)(log2((long long)9)/log2((long long)3))<<endl;
    while(t--) {
        scanf("%lld%lld",&n,&k);
        int ans=0;
        while(n!=0) {
            long long z=1;
            while(z*k<=n) {
                z=z*k;
            }
            //printf("%lld %lld %lld\n",n,z,v);
            n-=z;
            ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
