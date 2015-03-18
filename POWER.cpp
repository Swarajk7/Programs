#include<bits/stdc++.h>
using namespace std;
long long M = 1000000007;
template <typename T>
T modpow(T base, T exp) {
  base %= M;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % M;
    base = (base * base) % M;
    exp >>= 1;
  }
  return result;
}
int main()
{
    int n,t;
    cin>>t;
    while(t--) {
        cin>>n;
        long long k=n,cnt=0;
        while(k!=0) {
            if(k&1) cnt++;
            k>>=1;
        }
        cout<<modpow((long long)2,cnt*n)<<endl;
    }
    return 0;
}
