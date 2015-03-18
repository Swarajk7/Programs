#include<bits/stdc++.h>
using namespace std;
int solve(string s,int i,int prevsum,int left) {
    if(i==s.length()) return 1;
    if(left<prevsum) return 0;
    //cout<<i<<endl;
    int px=s[i]-'0';
    int ans=1;
    for(int j=i+1;j<s.length();j++) {
        if(px>=prevsum) ans += solve(s,j,px,left-px);
        px=px+s[j]-'0';
    }
    return ans;
}
int getSum(string s) {
    int a=0;
    for(int i=0;i<s.length();i++) a+=s[i]-'0';
    return a;
}
int main() {
    string s;
    cin>>s;
    int t=1;
    while(s!="bye") {
        int val=getSum(s);
        cout<<t<<". "<<solve(s,0,0,val)<<endl;
        cin>>s;
        t++;
    }
    return 0;
}
