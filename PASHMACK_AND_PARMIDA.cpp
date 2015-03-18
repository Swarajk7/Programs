#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
#define MAX 1000003
class FenwickTree {
    vector<int> tree;
    public: FenwickTree() {
        tree.resize(MAX,0);
    }
    int read(int idx){
        int sum = 0;
        while (idx > 0){
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    void update(int idx ,int val){
        while (idx <= MAX){
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
};
int main() {
    int n,a;
    scanf("%d",&n);
    v.resize(n);
    map<int,int> m;
    vector<int> dp(n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a);
        v[i]=a;
        dp[i]=a;
    }
    sort(dp.begin(),dp.end());
    int sz = unique(dp.begin(), dp.end()) - dp.begin();
    //cout<<sz<<endl;
    for (int i = 0; i < n; i ++) v[i] = lower_bound(dp.begin(), dp.begin() + sz, v[i]) - dp.begin();
    for(int i=0;i<n;i++) {
        //cout<<v[i]<<endl;
        a=v[i];
        if(m.find(a)==m.end()) m[a]=1;
        else m[a]+=1;
        dp[i]=m[a];
    }
    vector<int> r_dp(n);
    map<int,int> m1;
    for(int i=n-1;i>=0;i--) {
        a=v[i];
        if(m1.find(a)==m1.end()) m1[a]=1;
        else m1[a]+=1;
        r_dp[i]=m1[a];
    }
    //reverse(r_dp.begin(),r_dp.end());
    long long ans=0;
    FenwickTree ft;
    for(int i=0;i<n;i++)
        ft.update(r_dp[i],1);
    //for(int i=0;i<n;i++) cout<<r_dp[i]<<" ";cout<<endl;
    for(int i=0;i<n;i++) {
        ft.update(r_dp[i],-1);
        ans+=(long long)ft.read(dp[i]-1);
        //cout<<ans<<endl;
    }
    printf("%I64d\n",ans);
    return 0;
}
