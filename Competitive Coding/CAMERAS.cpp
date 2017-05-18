#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> > v,v1;
vector<int> num;
bool cmp(pair<int,int> p1,pair<int,int> p2) {
    if(p2.first!=p1.first) {
        return p1.first<p2.first;
    } else return p1.second<p2.second;
}
int main()
{
    int n,k,a,b;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) {
        scanf("%d",&a);
        num.push_back(a);
    }
    sort(num.begin(),num.end());
    for(int i=0;i<k;i++) {
        scanf("%d%d",&a,&b);
        v1.push_back(make_pair(a,b));
    }
    sort(v1.begin(),v1.end(),cmp);
    int e=v1[0].second;
    v.push_back(v1[0]);
    for(int i=1;i<k;i++) {
        a=v1[i].first;
        b=v1[i].second;
        if(a<=e) a=e+1;
        if(a<=b) v.push_back(make_pair(a,b));
        //cout<<a<<" "<<b<<endl;
        e=b;
    }
    int ans=0;
    for(int i=0;i<v.size();i++) {
        //cout<<v[i].first<<","<<v[i].second<<endl;
        int x2=std::upper_bound (num.begin(), num.end(), v[i].second)-num.begin();
        int x1=std::lower_bound (num.begin(), num.end(), v[i].first)-num.begin();
        ans+=(x2-x1+1);
        if(num[x2]!=v[i].second) ans--;
    }
    printf("%d\n",ans);
    return 0;
}
