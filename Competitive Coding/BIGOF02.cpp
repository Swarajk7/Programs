#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii > v;
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
            v.push_back(make_pair(a,b));
        }
        sort(v.begin(),v.end(),cmp);
        int i,j;
        i=0;
        int ans=1;
        for(j=1;j<n;j++) {
            if(v[j].first>v[i].second) {
                ans++;
                i=j;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

