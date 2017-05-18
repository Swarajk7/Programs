#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    int t,n;
    scanf("%d",&t);
    string s;
    while(t--){
        int mx=-1;
        scanf("%d",&n);
        cin>>s;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                int no_0=0,no_1=0;
                for(int k=i;k<=j;k++) {
                    if(s[k]=='1') no_1+=1;
                    else no_0+=1;
                }
                if(i==j) {
                    if(s[i]=='1') mx=max(mx,1);
                    else mx=max(mx,0);
                } else if(no_1>no_0) mx=max(mx,j-i+1);
            }
        }
        //cout<<mx<<endl;
        int ans=0,no_1=0,no_0=0;
        for(int i=0;i<=n-mx;i++) {
            no_1=0;no_0=0;
            for(int k=i;k<i+mx;k++) {
                    if(s[k]=='1') no_1+=1;
                    else no_0+=1;
                }
            if(no_1>no_0) {
                ans++;
                i+=mx;
            }
        }
        cout<<ans*mx<<endl;
    }
    return 0;
}
