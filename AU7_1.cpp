#include<bits/stdc++.h>
using namespace std;
#define N 10
int ar[1<<N];
void clear() {
    for(int i=0;i<(1<<N);i++) ar[i]=0;
}
int main() {
    int t;
    int n;
    scanf("%d",&t);
    while(t--) {
        clear();
        scanf("%d",&n);
        char c[22];
        for(int i=0;i<n;i++) {
            scanf("%s",c);
            int v=0;
            for(int i=0;i<strlen(c);i++) {
                int p=c[i]-'0';
                v|=(1<<p);
            }
            ar[v]++;
        }
        long long ans=0;
        for(int i=0;i<(1<<N);i++) {
            if(ar[i]!=0) {
                ans += (ar[i]*(ar[i]-1))/2;
                for(int j=0;j<(1<<N);j++) {
                    if(i!=j && ar[j]!=0 && (i&j)!=0) {
                       // cout<<i<<" "<<j<<endl;
                        ans += ar[j]*ar[i];
                    }
                }
            }
        }
        cout<<ans/2<<endl;
    }
    return 0;
}
