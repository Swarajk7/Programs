#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    string s;
    while(t--) {
        cin>>s;
        int l=0;
        int mxbal=INT_MIN;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='(') l++;
            else l--;
            mxbal=max(mxbal,l);
        }
        string ans="";
        for(int i=0;i<mxbal;i++) ans.push_back('(');
        for(int i=0;i<mxbal;i++) ans.push_back(')');
        cout<<ans<<endl;
    }
    return 0;
}
