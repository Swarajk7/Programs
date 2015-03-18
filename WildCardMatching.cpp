#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector< vector<int> > dp;
public:
    bool isMatch(const char *s, const char *p) {
        dp.resize(strlen(s), vector<int>(strlen(p),-1));
        int len_s=strlen(s);
        int len_p=strlen(p);
        return check(s,0,len_s,p,0,len_p);
    }
    bool check(const char *s,int i,int s_len,const char *p,int j,int p_len) {
        if(i==s_len && j==p_len) return true;
        if(i==s_len || j==p_len) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool flag=false;
        if(p[j]=='?') {
            flag = check(s,i+1,s_len,p,j+1,p_len);
        } else if(p[j]=='*') {
            for(int k=i;k<=s_len;k++) {
                flag= flag || check(s,k,s_len,p,j+1,p_len);
            }
        } else {
            if(p[j]==s[i]) flag = check(s,i+1,s_len,p,j+1,p_len);
            else flag = false;
        }
        dp[i][j]=flag;
            return flag;
    }
};
int main()
{
    char *s2="aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba",*s1="a*******a";
    Solution s;
    cout<<s.isMatch(s2,s1);
    return 0;
}
