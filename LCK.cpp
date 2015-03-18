#include<bits/stdc++.h>
using namespace std;
bool isp(int n) {
    if(n<2) return 0;
    if(n==2) return 1;
    for(int i=2;i<n;i++) {
        if(n%i==0) return 0;
    }
    return 1;
}
int main()
{
    int t1;
    cin>>t1;
    string s;
    long long t=0;
    while(t1--) {
        cin>>s;
        int sm=0;
        for(int i=0;i<s.length();i++) {
            sm+=s[i]-'0';
        }
        if(isp(sm)) t = (t<<1)|1;
        else t<<=1;
    }
    cout<<t;
    return 0;
}
