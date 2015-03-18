#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node {
    int  w;
    ll p;
    node(int a) {
        w=a;
    }
    void setP(ll b) { p=b; }
};
bool comp(node a,node b) {
    if(a.p==b.p) return a.w<b.w;
    else return a.p>b.p;
}
vector<node> v;
ll dp[2005][2005][3];
ll rec(int i,int &n,int W,int cnt) {
    if(i==n) {
        if(W<0) return -99999999999999;
        else return 0;
    }
    if(W<0) return -99999999999999;
    if(dp[i][W][cnt]!=-1) return dp[i][W][cnt];
    ll ans=0;
    if(cnt==0) {
        ans=max(3*v[i].p+rec(i+1,n,W-v[i].w,cnt+1),rec(i+1,n,W,cnt));
    } else if(cnt==1) {
        ans=max(2*v[i].p+rec(i+1,n,W-v[i].w,cnt+1),rec(i+1,n,W,cnt));
    } else ans=max(v[i].p+rec(i+1,n,W-v[i].w,cnt),rec(i+1,n,W,cnt));
    dp[i][W][cnt]=ans;
    return ans;
}
void clearDP() {
    for(int i=0;i<2005;i++) {
        for(int j=0;j<2005;j++) {
            dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=-1;
        }
    }
}
int main() {
    int n,w;
    int a;ll p;
    cin>>n>>w;
    for(int i=0;i<n;i++) {
        cin>>a;
        v.push_back(node(a));
    }
    for(int i=0;i<n;i++) {
        cin>>p;
        v[i].setP(p);
    }
    sort(v.begin(),v.end(),comp);
    clearDP();
    cout<<rec(0,n,w,0);
}
