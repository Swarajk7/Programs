#include<bits/stdc++.h>
using namespace std;
#define MAX 10005
int h[MAX];
map<int,int> mp;
int gcd(int a,int b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    int t,n,f,a;
    scanf("%d",&t);
    while(t--) {
        int ans=0;
        mp.clear();
        scanf("%d%d",&n,&f);
        for(int i=0;i<n;i++) {
            cin>>a;h[i]=a;
            if(mp.find(a)==mp.end()) {
                mp[a]=1;
            } else mp[a]+=1;
        }
        int mx=*max_element(h,h+n);
        sort(h,h+n);
         ans=0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int x=max(h[i],h[j])/min(h[i],h[j]);
                if(x==f || x==1) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
