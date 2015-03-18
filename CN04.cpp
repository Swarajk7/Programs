#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    string s;
    cin>>t;
    while(t--) {
        cin>>s;
        set<string> a;
        for(int i=0;i<s.length();i++) {
            for(int j=1;j<=s.length()-i;j++) {
                string k = s.substr(i,j);
                a.insert(k);
            }
        }
        cout<<a.size()<<endl;
    }
    return 0;
}
