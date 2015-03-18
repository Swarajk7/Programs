#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int ar[MAX];
int main() {
    int t,n,k;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d",ar+i);
        sort(ar,ar+n);
        int r=ar[n-1]-ar[0],l=1;
        int gans=-1;
        while(l<=r) {
            int last=ar[0];
            int ans=(l+r)>>1;
            int p=k-1;
            for(int i=1;i<n;i++) {
                if(ar[i]-last>=ans) {
                    p--;
                    last=ar[i];
                }
            }
            //cout<<ans<<" "<<p<<endl;
            if(p>0) r=ans-1;
            else {
                gans=ans;
                l=ans+1;
            }
        }
        printf("%d\n",gans);
    }
    return 0;
}
