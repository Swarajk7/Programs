#include<bits/stdc++.h>
using namespace std;
int ar[2005];
int main()
{
    int n;
    scanf("%d",&n);
    while(n!=0) {
        long long ans=0;
        for(int i=0;i<n;i++) scanf("%d",&ar[i]);
        sort(ar,ar+n);
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                cout<<ar[i]+ar[j]<<" ";
                int k=(lower_bound(ar+j+1,ar+n,ar[i]+ar[j]-1)-ar)/sizeof(int);
                cout<<i<<" "<<j<<" "<<n-k<<endl;
                ans=ans+k;
            }
        }
        printf("%lld\n",ans);
        scanf("%d",&n);
    }
}
