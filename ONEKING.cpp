#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> v;
#define mp make_pair
bool cmp(pii a,pii b) {
    if(a.second==b.second) return a.first<b.first;
    else return a.second<b.second;
}
int main() {
    int t,n,a,b;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        v.clear();
        for(int i=0;i<n;i++) {
            scanf("%d%d",&a,&b);
            v.push_back(mp(a,b));
        }
        sort(v.begin(),v.end(),cmp);
        int e=v[0].second;
        int ans=1;
        for(int i=1;i<n;i++) {
            if(v[i].first > e) {
                ans++;
                e=v[i].second;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
