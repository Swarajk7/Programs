#include<bits/stdc++.h>
using namespace std;
int main() {
    int t,n,p;
    string k;
    cin>>t;
    while(t--) {
        cin>>n>>k>>p;
        int ans=0;
        if(k=="even") {
            ans=2*p-1;
        } else {
            ans=2*p;
        }
        cout<<ans<<endl;
    }
    return 0;
}
