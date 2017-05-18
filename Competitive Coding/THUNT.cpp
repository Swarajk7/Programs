#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k=n;
    int x=1;
    bool flag=true;
    int l=0;
    int r=n-1;
    x=1;
    int ar[n];
    while(k--) {
        if(flag) { ar[l]=x; l++; flag=false;}
        else { ar[r]=x; r--; flag=true; }
        x+=n;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-1;j++) cout<<ar[i]+j<<"*"; cout<<ar[i]+n-1<<endl;
    }
    return 0;
}
