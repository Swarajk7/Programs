// love_hunters
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
ll power(ll a,ll b){
ll res = 1;
 while(b){
	if(b&1) res = (res*a)%mod;
	a = (a*a)%mod;
	b >>= 1;
 }
 return res;
}
int a,b,c,d,x,y,z;
#define REP(i,n) for (int i = 1; i <= n; i++)
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const int K = 4;
matrix mul(matrix A, matrix B){
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}
// computes A ^ p
matrix pow(matrix A, int p){
    if (p == 1) return A;
    if (p % 2) return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}
ll solve(int N){
    vector<ll> F1(K+1);
    F1[1] = x;
    F1[2] = y;
    F1[3] = z;
    F1[4] = d;
    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = 0, T[1][2] = 1 ; T[1][3] = 0;T[1][4] = 0;
    T[2][1] = 0, T[2][2] = 0; T[2][3] = 1;T[2][4] = 0;
    T[3][1] = c, T[3][2] = b; T[3][3] = a;T[3][4] = 1;
    T[4][1] = 0, T[4][2] = 0; T[4][3] = 0;T[4][4] = 1;
    if (N == 1)
        return 1;
    T = pow(T, N-1);
    ll res = 0;
    REP(i, K)
        res = (res + T[1][i] * F1[i]) % MOD;
    return res;
}
int main(){
  int t,n;
  scanf("%d",&t);
  while(t--){
	scanf("%d %d %d %d %d %d %d %d",&a,&b,&c,&d,&x,&y,&z,&n);
	printf("%lld\n",solve(n));
  }
  return 0;
}
