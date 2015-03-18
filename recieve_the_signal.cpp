#include<bits/stdc++.h>
using namespace std;
int anss=0,k=0;
void cal(string s,int i,int ans,int a1) {
    if(i==s.length()) {
        k++;
        if(ans==a1) anss++; return;
    }
    else {
        if(s[i]=='+') cal(s,i+1,ans+1,a1);
        else if(s[i]=='-') cal(s,i+1,ans-1,a1);
        else if(s[i]=='?') {
            cal(s,i+1,ans+1,a1);
            cal(s,i+1,ans-1,a1);
        }
    }
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int a1=0;
    for(int i=0;i<s1.length();i++) {
        if(s1[i]=='+') a1++;
        else a1--;
    }
    cal(s2,0,0,a1);
    double a2=anss;
    printf("%.9lf",a2/k);
    return 0;
}
