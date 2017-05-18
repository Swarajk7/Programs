#include<bits/stdc++.h>
using namespace std;
#define N 100005
int ar[N];
long long getSum(int i) {
    if(i==0) {
        return (ar[0]*(ar[0]-1))/2;
    } else {
        int a=ar[i-1]+1;
        long long n=ar[i]-ar[i-1]-1;
        return a*n+n*(n-1);
    }
}
long long get(int k) {
    long long ans=0;
    for(int i=0;i<k;i++) {
        ans+=getSum(i);
        if(ans<ar[i]) return ans+1;
    }
    return ans+1;
}
int main() {
    int t;
    int n,k;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&k);
        for(int i=0;i<k;i++) {
            scanf("%d",ar+i);
        }
        sort(ar,ar+k);
        ar[k]=n+1;
        long long val=get(k+1);
        cout<<val<<endl;
        if(val&1) cout<<"Chef\n";
        else cout<<"Mom\n";
    }
    return 0;
}
