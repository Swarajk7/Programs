#include<bits/stdc++.h>
using namespace std;
string s;
int LCS(int i,int j) {
    if(i==s.length() || j==s.length()) return 0;
    int ans=0;
    if(i!=j) {
        if(s[i]==s[j]) ans=LCS(i+1,j+1)+1;
        else ans=max(LCS(i+1,j),LCS(i,j+1));
    }
    else ans=max(LCS(i+1,j),LCS(i,j+1));
    return ans;
}
int main() {
    cin>>s;
    cout<<LCS(0,0);
    return 0;
}
