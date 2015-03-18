#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    string s;
    while(t--) {
        cin>>s;
        int len=s.length();
        for(int i=len-1;i>=3;i--) {
            char a,b,c,d;
            a=s[i];b=s[i-1];c=s[i-2];d=s[i-3];
            if((a=='F' || a=='?') && (b=='E' || b=='?') &&(c=='H' || c=='?') &&(d=='C' || d=='?')) {
                s[i-3]='C';
                s[i-2]='H';s[i-1]='E';s[i]='F';
            }
        }
        for(int i=0;i<len;i++) if(s[i]=='?') s[i]='A';
        cout<<s<<endl;
    }
    return 0;
}
