#include<bits/stdc++.h>
using namespace std;
int k[20];
int cal(int i,int r,int g) {
    if(r<0 || g<0) return 0;
    if(r<i && g<i) {
        k[i]++;
        return 1;
    }
    int ans1=0,ans2=0;
    if(i<=r) {
        ans1=cal(i+1,r-i,g);
    }
    if(i<=g) {
        ans2=cal(i+1,r,g-i);
    }
    return ans1+ans2;
}
int main()
{
    int r,g;
    cin>>r>>g;
    cout<<cal(1,r,g);
    for(int i=0;i<20;i++) cout<<k[i]<<" ";
    return 0;
}
