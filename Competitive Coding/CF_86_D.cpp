#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define VAL 1000006
#define BLOCK 500
typedef long long ll;
int n;
ll val[VAL], tree[VAL], ans[N];
int A[N];
struct query {
    int i,l,r;
} q[N];
bool comp(query a,query b) {
    if(a.l/BLOCK == b.l/BLOCK) {
        return a.r < b.r;
    } else
    return a.l/BLOCK < b.l/BLOCK;
}
void update(int idx ,ll val){
 while (idx <= VAL){
  tree[idx] += val;
  idx += (idx & -idx);
 }
}
ll read(int idx){
 ll sum = 0;
 while (idx > 0){
  sum += tree[idx];
  idx -= (idx & -idx);
 }
 return sum;
}
void add(int ind) {
    int v=A[ind];
    ll k=val[v];
    ll z= sqrt(val[v]/v);
    z=(z+1)*(z+1);
    val[v]=z*v;
    //cout<<v<<" "<<val[v]<<" "<<k<<endl;
    update(v,val[v]-k);
}
void rmv(int ind) {
    int v=A[ind];
    ll k=val[v];
    //if(k==0) return;
    ll z= sqrt(abs(val[v]/v));
    z=(z-1)*(z-1);
    val[v]=z*v;
    update(v,val[v]-k);
}
void clearTV() {
    for(int i=0;i<VAL;i++) {
        tree[i]=0;
        val[i]=0;
    }
}
int main() {
    int m,L,R;
    scanf("%d%d",&n,&m);

    for(int i=0; i<n; i++)
		scanf("%d", &A[i]);
    clearTV();
    for(int i=0;i<m;i++) {
        scanf("%d%d",&L,&R);
        L--;R--;
        q[i].i=i; q[i].l=L; q[i].r=R;
    }

    sort(q,q+m,comp);

    int currentL=0,currentR=0;
    for(int i=0;i<m;i++) {
        L=q[i].l;R=q[i].r;
        while(currentL<L) {
            rmv(currentL);
            currentL++;
        }
        while(currentL>L) {
            add(currentL);
            currentL--;
        }
        while(currentR<=R) {
            add(currentR);
            currentR++;
        }
        while(currentR>R+1) {
            rmv(currentR-1);
            currentR--;
        }
        ans[q[i].i]=read(VAL-2);
        //for(int i=0;i<=3;i++) cout<<tree[i]<<" "; cout<<endl;
    }

    for(int i=0;i<m;i++) cout<<ans[i]<<endl;
}
