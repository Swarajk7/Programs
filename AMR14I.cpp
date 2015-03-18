#include<bits/stdc++.h>
using namespace std;
int n,m,s,p1,q;
int get(int x,int p) {
    if(x>=m) return m+((x-m+p)%(n-m+1));
    else {
        if(x+p<=m) return x+p;
        else return get(m,p-(m-x));
    }
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d%d%d",&n,&m,&s,&p1,&q);
        int prev1=1,prev2=1;
        int ans=0;
        for(int i=1;i<=s;i++) {
            prev1=get(prev1,p1);
            prev2=get(prev2,q);
            if(prev1==prev2) {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
