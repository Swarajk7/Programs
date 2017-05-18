#include<bits/stdc++.h>
using namespace std;
int sharp[1002],dot[1002];
int dps[1002],dpd[1002];
int main()
{
    int n,m,x1,y;
    cin>>n>>m>>x1>>y;
    string s;
    for(int i=0;i<n;i++) {
        cin>>s;
        for(int i=0;i<m;i++) {
            if(s[i]=='#') sharp[i]++;
            else dot[i]++;
        }
    }
    for(int i=0;i<m;i++) {
        dps[i]=INT_MAX;
        dpd[i]=INT_MAX;
    }
    dps[0]=dot[0];
    dpd[0]=sharp[0];
    int ans;
    for(int i=1;i<m;i++) {
        ans=dot[i];
        for(int x=1;x<x1 && i>=x;x++) ans+=dot[i-x];
        for(int x=x1;(x<=y-x1+1);x++) {
            if(i<x) break;
            //cout<<ans<<" ";
            dps[i]=min(dps[i],dpd[i-x]+ans);
            ans+=dot[i-x];
        }
        ans=sharp[i];
        for(int x=1;x<x1 && i>=x;x++) ans+=sharp[i-x];
        for(int x=x1;(x<=y-x1+1);x++) {
            if(i<x) break;
            dpd[i]=min(dpd[i],dps[i-x]+ans);
            ans+=sharp[i-x];
        }
    }
    cout<<min(dpd[m-1],dps[m-1]);
}
