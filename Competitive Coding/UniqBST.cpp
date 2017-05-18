#include<bits/stdc++.h>
int numTrees(int n) {
        if(n==0) return 1;
        if(n==1) return 1;
        int ans=0;
        for(int i=1;i<=n;i++) {
            ans += numTrees(i-1)*numTrees(n-i);
        }
        return ans;
    }
int main() {
    std::cout<<numTrees(4);
    return 0;
}
