#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        scanf("%d",&n);
        char c[50];
        sprintf(c,"%o",n);
        int k=strlen(c);
        //cout<<k<<endl;
        int ans=1;
        for(int i=0;i<k/2;i++) {
            if(c[i]!=c[k-1-i]) ans=-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
