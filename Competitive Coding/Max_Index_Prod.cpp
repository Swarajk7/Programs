#include<bits/stdc++.h>
using namespace std;
#define N 100005
int seg[4*N];
int ar[N];
int build(int l,int r,int index) {
    if(l==r) {
        seg[index]=ar[l];
        return ar[l];
    }
    int mid=(l+r)/2;
    int z1=build(l,mid,2*index);
    int z2=build(mid+1,r,2*index+1);
    seg[index]=max(z1,z2);
    return seg[index];
}
int query(int l,int r,int sl,int sr,int index) {
    if(sl<sr) return -1;
    if(l>sr || r<sl) return -1;
    if(l>=sl && r<=sr) return seg[index];
    if(l==r) return seg[index];
    int mid=(l+r)/2;
    int z1=query(l,mid,sl,sr,2*index);
    int z2=query(mid+1,r,sl,sr,2*index+1);
    return max(z1,z2);
}
int LEFT(int ind,int n) {
    int l=1,r=ind-1;
    while(l<=r) {
        //cout<<l<<" "<<r<<endl;
        if(l==r) { if(ar[l]>ar[ind]) return l; else return 0;}
        int mid=(l+r)/2;
        int z1=query(1,n,mid+1,r,1);
        int z2=query(1,n,l,mid,1);
        if(z1<ar[ind] && z2<ar[ind]) break;
        if(z1>ar[ind]) {
            l=mid+1;
        } else if(z2>ar[ind]) {
            r=mid;
        } else break;
    }
    return 0;
}
int RIGHT(int ind,int n) {
    int l=ind+1,r=n;
    while(l<=r) {
        //cout<<l<<" "<<r<<endl;
        if(l==r) { if(ar[l]>ar[ind]) return l; else return 0;}
        int mid=(l+r)/2;
        int z1=query(1,n,mid+1,r,1);
        int z2=query(1,n,l,mid,1);
        if(z1<ar[ind] && z2<ar[ind]) break;
        if(z2>ar[ind]) r=mid;
        else if(z1>ar[ind]) l=mid+1;
        else break;
    }
    return 0;
}
int main() {
    int n,a;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a);
        ar[i]=a;
    }
    build(1,n,1);
    long long ans=0,tans;
    //cout<<"YES\n";
    for(int i=1;i<=n;i++) {
        tans=LEFT(i,n);
        tans*=RIGHT(i,n);
        ans=max(ans,tans);
        //cout<<i<<" "<<LEFT(i,n)<<" "<<RIGHT(i,n)<<endl;
        //break;
    }
    printf("%lld\n",ans);
    return 0;
}
