#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n,x,a,sum;
    while(t--) {
        cin>>n>>x;
        sum=0;
        int mn=INT_MAX;
        for(int i=0;i<n;i++) {
            cin>>a;
            sum+=a;
            mn=min(mn,a);
        }
        int b=sum/x;
        int c=(sum-mn)/x;
        if(b==c) printf("-1\n");
        else printf("%d\n",b);
    }
    return 0;
}
