#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    string s1,s2;
    cin>>t;
    while(t--) {
        int hsh[26]={0};
        cin>>s1>>s2;
        for(int i=0;i<s1.length();i++) hsh[s1[i]-'a']++;
        for(int i=0;i<s2.length();i++) hsh[s2[i]-'a']--;
        bool ans=true;
        for(int i=0;i<26;i++) {
            if(hsh[i]!=0) ans=false;
        }
        ans?cout<<"YES\n":cout<<"NO\n";
    }
    return 0;
}
