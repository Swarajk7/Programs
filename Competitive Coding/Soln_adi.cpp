#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define sc(n) scanf("%d",&n);
#define pr(n) printf("%d\n",n);
#define MOD 1e9+7
#define PB push_back
#define MP make_pair
#define MAX 205
int n,m,k;
int arr[MAX][MAX];
vector<int> good;
map<pair<pair<int,int >,int >,int > mp;
int solve(int A,int B,int assgn){
    cout<<A<<" "<<B<<" "<<assgn<<endl;
if(mp.count(MP(MP(A,B),assgn)))
    return mp[MP(MP(A,B),assgn)];
int res;
if(assgn == k){
 res = 0;
 for(int i=0;i<k;i++){
     if(!((A>>i)&1))
        continue;
     for(int j=0;j<k;j++){
	     if(!((B>>j)&1))
	        continue;
     res += arr[good[i]][good[j]];
    }
 }
}
else if(assgn&1){
res = 1e9;
for(int i=0;i<k;i++){
      if(((A>>i)&1) || ((B>>i)&1))
        continue;
      res = min(res,solve(A,B|(1<<i),assgn+1));
    }
}
else{
res = (-1)*(1e9);
for(int i=0;i<k;i++){
      if(((A>>i)&1) || ((B>>i)&1))
        continue;
      res = max(res,solve(A|(1<<i),B,assgn+1));
    }
}
mp[MP(MP(A,B),assgn)] = res;
return res;
}
int main(){
int u,v,w;
sc(n);
sc(m);
sc(k);
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        arr[i][j] = 1e9;
    }
}
for(int i=1;i<=m;i++){
    sc(u);
    sc(v);
    sc(w);
    arr[u][v] = w;
    arr[v][u] = w;
}
for(int i=1;i<=k;i++){
    sc(u)
    good.PB(u);
}
for(int p=1;p<=n;p++){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j] = min(arr[i][j],arr[i][p]+arr[p][j]);
        }
    }
}
int ans;
ans = solve(0,0,0);
pr(ans);
return 0;
}
