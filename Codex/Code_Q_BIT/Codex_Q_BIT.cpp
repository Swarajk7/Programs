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
    int n,x,t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) {
            scanf("%d",&x);
            a[i]=x;
        }
        for(int i=0;i<n;i++) {
            scanf("%d",&x);
            b[i]=x;
        }
        long long ans=0;
        FenwickTree ft;
        for(int i=0;i<n;i++)
            ft.update(b[i],1);
        //for(int i=0;i<n;i++) cout<<r_dp[i]<<" ";cout<<endl;
        for(int i=0;i<n;i++) {
            ft.update(b[i],-1);
            ans+=(long long)ft.read(a[i]-1);
            //cout<<ans<<endl;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
