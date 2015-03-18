#include<bits/stdc++.h>
using namespace std;
#define N 100005
short ar[N];
int mem[N][11];
void seive() {
    for(int i=2;i<N;i++) {
        if(ar[i]!=0) continue;
        ar[i]=1;
        for(int j=i+i;j<N;j+=i) {
            ar[j]++;
        }
    }
}
void memoize() {
    //for(int j=2;j<N;j++) cout<<ar[j]<<" "; cout<<endl;
    for(int i=1;i<=11;i++) {
        mem[1][i]=0;
        for(int j=2;j<N;j++) {
            if(ar[j]==i) mem[j][i]=1+mem[j-1][i];
            else mem[j][i]=mem[j-1][i];
            //cout<<mem[j][i]<<" ";
        }
    }
}
int main() {
    seive();
    memoize();
    int t,x,y,k;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d",&x,&y,&k);
        int ans=0;
        ans-=mem[x-1][k];
        ans+=mem[y][k];
        printf("%d\n",ans);
    }
    return 0;
}
