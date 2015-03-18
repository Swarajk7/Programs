#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        for(int i=1;i<s.length();i++) {
            int left=i-1;
            int right=i;
            while(left>=0 && right<s.length() && s[left]==s[right]) {
                left--;
                right++;
            }
            cout<<left<<right;
            int k=right-left-1;
            if(k>ans.length()) {
                ans=s.substr(left+1,k);
            }
        }
        for(int i=0;i<s.length();i++) {
            int left=i;
            int right=i;
            while(left>=0 && right<s.length() && s[left]==s[right]) {
                left--;
                right++;
            }
            int k=right-left-1;
            if(k>ans.length()) {
                ans=s.substr(left+1,k);
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    cout<<s.longestPalindrome("bb");
    return 0;
}
