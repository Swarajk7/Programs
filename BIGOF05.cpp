#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll ar[10005],ar1[10005];
ll e[10005][100];
int primes[]= {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89 , 97};
ll power(ll a,ll b){
 ll res = 1;
 while(b){
	if(b&1) res = (res*a)%MOD;
	a = (a*a)%MOD;
	b >>= 1;
 }
 return res;
}
ll divide(int r,int l) {
    if(l==0) return ar1[r];
    // ar1[r]/ar1[l]
    ll b=ar1[l-1];
    ll a=ar1[r];
     ll ans = (a*power(b,MOD-2))%MOD;
}
int main() {
    int t,n,a,b,q;
    scanf("%d",&t);
    int len=sizeof(primes)/sizeof(int);
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%lld",ar+i);
        ar1[0]=ar[0];
        for(int i=1;i<n;i++) ar1[i]=(ar[i]*ar1[i-1]);
        for(int i=0;i<n;i++) {
            for(int j=0;j<100;j++) e[i][j]=0;
        }
        for(int ii=0;ii<n;ii++) {
            for(int i=0;i<len;i++) {
                while(ar[ii]%primes[i]==0) {
                    e[ii][primes[i]]++;
                    ar[ii]/=primes[i];
                }
            }
        }
        for(int ii=1;ii<n;ii++) {
            for(int i=0;i<len;i++) {
                e[ii][primes[i]]+=e[ii-1][primes[i]];
            }
        }
        scanf("%d",&q);
        while(q--) {
            scanf("%d%d",&a,&b);
            a--;b--;
            ll zz=1;
            for(int i=0;i<len;i++) {
                int k= e[b][primes[i]];
                if(a!=0) k-=e[a-1][primes[i]];
                zz = (zz*(k+1))%MOD;
            }
            ll zz1=divide(b,a);
            cout<<zz1<<" "<<zz<<endl;
        }
    }
    return 0;
}
