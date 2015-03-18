#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int t,a,b,c,d,x,y,v;
long long call(int x,int y,int z) {
    //cout<<x<<" "<<y<<" "<<z<<endl;
    if(z==2) {
        if(x==1 && y==1) return a*v;
        else if(x==1 && y==2) return c*v;
        else if(x==2 && y==1) return b*v;
        else return d*v;
    } else {
        int k=z/2;
        if(x>k && y>k) return (long long)d*(call(x-k,y-k,k));
        else if(x>k&& y<=k) return (long long)b*(call(x-k,y,k));
        else if(x<=k && y>k) return (long long)c*call(x,y-k,k);
        else return (long long)a*call(x,y,k);
    }
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&v);
        scanf("%d%d%d%d",&a,&b,&c,&d);
        scanf("%d%d",&x,&y);
        int z=max(x,y);
        z=(int)pow(2,ceil(log2(z)));
        long long val=call(y,x,z);
        printf("%lld\n",val);
    }
    return 0;
}
