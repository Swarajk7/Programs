#include<bits/stdc++.h>
using namespace std;
int cnt(string s) {
    set<string> st;
    for(int i=0;i<s.length();i++) {
        for(int j=1;j<=s.length()-i;j++) {
            string jj=s.substr(i,j);
            //cout<<jj<<endl;
            st.insert(jj);
        }
    }
    return st.size();
}
int main() {
    int t;
    string s;
    scanf("%d",&t);
    while(t--) {
        cin>>s;
        cout<<cnt(s)<<endl;
    }
    return 0;
}
