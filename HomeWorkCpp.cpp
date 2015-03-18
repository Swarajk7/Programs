#include<bits/stdc++.h>
using namespace std;
#define MAX 10000007
#define N 1e7
int ar[MAX];
int main() {
    for(int i=0;i<MAX;i++) ar[i]=0;
    for(int i=2;i<MAX;i++) {
        if(ar[i]!=0) continue;
        for(int j=i;j<MAX;j+=i) ar[j]++;
    }
    int t,a,b,k;
    scanf("%d",&t);
    for(int t1=1;t1<=t;t1++) {
        scanf("%d%d%d",&a,&b,&k);
        int cnt=0;
        for(int i=a;i<=b;i++) if(ar[i]==k) cnt++;
        printf("Case #%d: %d\n",t1,cnt);
    }
    return 0;
}
