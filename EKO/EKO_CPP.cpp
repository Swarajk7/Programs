#include<bits/stdc++.h>
using namespace std;
typedef pair<int,bool> pib;
vector<pib > v;
int main() {
    int t,n,a,b;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        v.clear();
        for(int i=0;i<n;i++) {
            scanf("%d%d",&a,&b);
            pib p1=make_pair(a,true);
            pib p2=make_pair(b,false);
            v.push_back(p1);
            v.push_back(p2);
        }
        sort(v.begin(),v.end());
        int ans=0,fans=0;
        for(int i=0;i<v.size();i++) {
            if(v[i].second) ans++;
            else ans--;
            fans=max(ans,fans);
        }
        printf("%d\n",fans);
    }
    return 0;
}
