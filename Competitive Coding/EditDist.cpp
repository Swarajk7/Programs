#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector< vector<int> > dp;
public:
    int minDistance(string word1, string word2) {
        dp.clear();
        int k=max(word1.length(),word2.length());
        dp.resize(k);
        for(int i=0;i<dp.size();i++) dp[i].resize(k,-1);
        return dist(word1,0,word2,0);
    }
    int dist(string a,int i,string b,int j) {
        if(i==a.length()) return b.length()-j;
        if(j==b.length()) return a.length()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]) return dist(a,i+1,b,j+1);
        int k= min(1+dist(a,i+1,b,j),1+dist(a,i,b,j+1));
        k= min(k ,1+dist(a,i+1,b,j+1));
        dp[i][j]=k;
        return k;
    }
};
int main() {
    Solution s;
    cout<<s.minDistance("","");
    return 0;
}
