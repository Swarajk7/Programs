#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll mat[102][102][102];
int n;
void mul(int s,int a,int b) {
    int i,j,k;
    for(i=0;i < n;i++) {
        for(j=0;j < n;j++) {
            mat[i][j][s]=0;
            for(k=0;k < n;k++){
                mat[i][j][s]=mat[i][j][s]+mat[i][k][a]*mat[k][j][b];
                mat[i][j][s]%=MOD;
            }
        }
    }
}
void multiply(int L) {
    for(int i=2;i<=8;i++) {
        mul(i,i-1,1);
    }
}
void expFast(int L) {
    if(L==1) return;
    if(L&1) {
        expFast(L/2);
        mul(101,L/2,L/2);
        mul(L,101,1);
    } else {
        expFast(L/2);
        mul(L,L/2,L/2);
    }
}
int main() {
    int t,e,a,b,q,l;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&e);
        for(int i=0;i<102;i++) {
            for(int j=0;j<102;j++) {
                for(int k=0;k<102;k++) mat[i][j][k]=0;
            }
        }
        while(e--) {
            scanf("%d%d",&a,&b);
            mat[a][b][1]+=1;
            mat[b][a][1]+=1;
        }
        scanf("%d%d",&q,&l);
        expFast(l);
        while(q--) {
            scanf("%d%d",&a,&b);
            printf("%lld\n",mat[a][b][l]);
        }
    }
    return 0;
}
