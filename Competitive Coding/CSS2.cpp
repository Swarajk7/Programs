#include<bits/stdc++.h>
using namespace std;
struct val {
    int id,attr,valx,pri;
    val(int a,int b,int c,int d) {
        id=a;attr=b;valx=c;pri=d;
    }
};
bool cmp(val a,val b) {
    if(a.id==b.id) {
        if(a.attr==b.attr) {
            return a.pri<b.pri;
        } else return a.attr<b.attr;
    } else return a.id<=b.id;
}
vector<val> v;
map< pair<int,int> , int > mp;
int main()
{
    int n,m,a,b,c,d;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        cin>>a>>b>>c>>d;
        v.push_back(val(a,b,c,d));
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++) {
        //cout<<v[i].id<<" "<<v[i].attr<<" "<<v[i].valx<<" "<<v[i].pri<<endl;
        pair<int,int> p=make_pair(v[i].id,v[i].attr);
        mp[p]=v[i].valx;
    }
    while(m--) {
        cin>>a>>b;
        pair<int,int> p=make_pair(a,b);
        cout<<mp[p]<<endl;
    }
    return 0;
}
