#include <algorithm>
#include <cstdio>
#include <cstring>
#include<iostream>
using namespace std;
typedef long long llong;
const int MAXN =100020;
llong tree[MAXN], A[MAXN], B[MAXN];
llong read(int idx){
 llong sum = 0;
 while (idx > 0){
  sum += tree[idx];
  idx -= (idx & -idx);
 }
 return sum;
}

void update(int idx ,llong val){
 while (idx <= MAXN){
  tree[idx] += val;
  idx += (idx & -idx);
 }
}

int main() {
   int t,n;
   scanf("%d",&t);
   while(t--) {
       scanf("%d",&n);
      memset(tree, 0, sizeof(tree));
      for(int i = 0; i < n; ++i) {
         scanf("%lld",&A[i]);
      }
      for(int i=0;i<n;i++)
      {
      	scanf("%lld",&B[i]);
      }
    llong inv_count = 0;
    update(B[n-1],1);
      for(int i = n-2;i>=0; i--) {
         llong x = read(A[i]-1);
         inv_count += x;
         update(B[i],1);
      }
      printf("%lld\n",inv_count);
      for(int i=0;i<MAXN;i++) tree[i]=0;
   }
   return 0;
}
