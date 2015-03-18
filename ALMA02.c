#include<stdio.h>
#include<math.h>
int main() {
    long long t,n,k;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld%lld",&n,&k);
        long long p=1,j=9;
        while(k>0) {
            if(k>p*j) {
                k-=p*j;
                j*=10;
                p++;
            }
            else break;
        }
        int ans,i;
        if(k==0) ans=9;
        else {
            long long v=(k-1)/p;
            long long v1=k-v*p,z=1;
            for(i=0;i<p-1;i++) z*=10;
            z+=v;
            int xx=p-v1;
            while(xx>=0) {
                ans=z%10;
                z/=10;
                xx--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
