#include<stdio.h>
#define MOD 1000000007
int main() {
    int t,n,k;
    scanf("%d",&t);
    while(t--) {
        long long ans=1;
        scanf("%d%d",&n,&k);
        int z=n-k;
        while(n>z) {
            ans=(ans*n)%MOD;
            n--;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
