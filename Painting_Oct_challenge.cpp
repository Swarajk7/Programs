#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,x,m,xt;
    char c,ct;
    //scanf("%d",&t);
    cin>>t;
    long long ans;
    while(t--) {
        ans=0;
        cin>>n>>m;
        cin>>c>>x;
        ct=c;
        xt=x;
        for(int i=1;i<m;i++) {
            cin>>c>>x;
            if(c==ct) {
                xt=x;
            }
            else {
                ans=ans+(x-xt);
                ct=c;
                xt=x;
            }
            //cout<<c<<" "<<x<<endl;
        }
        if(ans==0) ans=1;
        printf("%lld\n",ans);
    }
    return 0;
}
