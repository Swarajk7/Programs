#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define mp make_pair 
#define pb push_back
int main() {
    int n,k;
    long long s,t;
    cin>>n>>k;
    std::priority_queue<pll, std::vector<pll>, std::greater<pll> > mhp;
    vector<pll> v;
    queue<int> q;
    vector<long long> ans(n,-1);
    for(int i=0;i<k;i++) q.push(i);
    for(int i=0;i<n;i++) {
        cin>>s>>t;
        v.pb(mp(s,t));
    }
    int item=0;
    long long cur=0;
    while(item<n) {
        while(!q.empty()) {
            long long st = max(v[item].first,cur);
            long long et = st + v[item].second;
            mhp.push(mp(et,q.front()));
            ans[item] = et;
            //cout<<"Et="<<et<<" "<<cur<<" "<<q.front()<<endl;
            q.pop();
            item++;
        }
        if(!mhp.empty()) {
            pll tp = mhp.top();
            mhp.pop();
            cur = tp.first;
            q.push(tp.second);
        }
    }
    for(auto i:ans) cout<<i<<endl;
    return 0;
}