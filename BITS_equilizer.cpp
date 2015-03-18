#include<bits/stdc++.h>
using namespace std;
int proc(string s,string t) {
    int t0=0,s0=0;
    for(int i=0;i<s.length();i++) if(s[i]=='0') s0++;
    for(int i=0;i<s.length();i++) if(t[i]=='0') t0++;
    int ans=0;
    //cout<<s0<<" "<<t0<<endl;
    if(t0>s0) {
        int diff=t0-s0;
        for(int i=0;i<s.length() && diff>0;i++) {
            if(s[i]=='?' && t[i]=='0') {
                s[i]='0';
                diff--; ans++;
            }
        }
        for(int i=0;i<s.length() && diff>0;i++) {
            if(s[i]=='?') {
                s[i]='0';
                diff--; ans++;
            }
        }
        for(int i=0;i<s.length();i++) {
            if(s[i]=='?') {
                s[i]='1';
                ans++;
            }
        }
    }
    //case 2
    else if(s0==t0) {
        for(int i=0;i<s.length();i++) {
            if(s[i]=='?') {
                s[i]='1';
                ans++;
            }
        }
    } else {
        for(int i=0;i<s.length();i++) {
            if(s[i]=='?') {
              s[i]='1'; ans++;
            }
        }
        int diff=s0-t0;
        for(int i=0;i<s.length() && diff>0;i++) {
            if(s[i]=='0' && t[i]=='1') {
                s[i]='1';
                diff--; ans++;
            }
        }
       /* for(int i=0;i<s.length() && diff>0;i++) {
            if(s[i]=='0') {
                s[i]='1';
                diff--; ans++;
            }
        }*/
    }
    int xx=0;
    //cout<<s<<endl;
    //cout<<t<<endl;
    for(int i=0;i<s.length();i++) {
        if(s[i]!=t[i]) xx++;
    }
    if(xx&1) return -1;
    else return ans+(xx/2);
}
int main()
{
    int t;
    string s1,s2;
    cin>>t;
    for(int t1=1;t1<=t;t1++) {
        cin>>s1>>s2;
        cout<<"Case "<<t1<<": "<<proc(s1,s2)<<endl;
    }
    return 0;
}
