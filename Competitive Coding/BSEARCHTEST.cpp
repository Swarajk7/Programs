#include<bits/stdc++.h>
using namespace std;
int ar[100],n;
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
    ar[0]=1;ar[1]=7;ar[2]=12;ar[3]=18;ar[4]=24;
    n=5;
    for(int i=-3;i<=26;i++) {
        int val=i;
        assert(upper_boundC(val)==(upper_bound(ar,ar+n,val)-ar));
        assert(lower_boundC(val)==(lower_bound(ar,ar+n,val)-ar));
        cout<<val<<endl;
    }
    return 0;
}
