#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    long long n;
    scanf("%d",&t);
    while(t--) {
        scanf("%lld",&n);
        int c=0;
        while(n!=0) {
            c++;
            n>>=1;
        }
        n=1;
        while(c-->1) n<<=1;
        n=2*n-1;
        printf("%lld\n",n);
    }
    return 0;
}
