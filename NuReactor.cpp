#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3;
int rec(int i,int j,int k) {
    if(k==s3.length()) return INT_MAX;
    if(i==s1.length()|| j==s2.length()) return 0;
    if(s1[i]==s2[j]) {

    }
}
int main() {
    cin>>s1>>s2>>s3;
    cout<<rec(0,0,0);
}
