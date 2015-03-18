#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
bool LPS_helper(string s,int l,int r,int &ans) {
    if(l>r) return true;
    cout<<l<<" "<<r<<endl;
    if(l==r) {
        ans=max(ans,1);
        return true;
    }
    else if(s[l]==s[r]) {
        bool val=LPS_helper(s,l+1,r-1,ans);
        if(val) {
            ans=max(ans,r-l+1);
            return true;
        } else return false;
    }
    else {
        LPS_helper(s,l+1,r,ans);
        LPS_helper(s,l,r-1,ans);
        return false;
    }
}
int LPS(string s) {
    int ans=0;
    if(LPS_helper(s,0,s.length()-1,ans)) ans=s.length();
    return ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<LPS(s);
    return 0;
}
