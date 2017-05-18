#include<bits/stdc++.h>
using namespace std;
#define MAX 100000*22
vector<int> mem[MAX];
int ar[22];
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d",&ar[i]);
        for(int i=0;i<(1<<n);i++) {
            int s=0;
            int j=i;
            int cnt=n-1;
            while(j!=0) {
                if(j&1) s+=ar[cnt];
                cnt++;j>>=1;
            }
            v[s].push_back(i);
        }
        for(int i=1;i<MAX;i++) {
            int s=1;
            if(v[i].size()>=k)
            for(int j=0;j<v[i].size();j++) s=s&v[i][j];
        }
    }
}
