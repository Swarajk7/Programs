#include<bits/stdc++.h>
using namespace std;
struct node {
    int s,e,cost;
    node(int a,int b,int c) {
        s=a;e=b;cost=c;
    }
};
vector<node> v;
vector<int> dp;
bool cmp(node x,node y) {
    if(x.e==y.e) {
        if(x.s==y.s) return x.s<y.s;
        else return x.cost<y.cost;
    }
    else return x.e<y.e;
}
bool cmp2(node x,int val) {
    return x.e<val;
}
int get(int val) {
    vector<node>::iterator k=lower_bound(v.begin(),v.end(),val,cmp2);
    return k-v.begin()-1;
}
int main() {
    int t,N,a,b,c;
    scanf("%d",&t);
    while(t--) {
        v.clear();
        scanf("%d",&N);
        for(int i=0;i<N;i++) {
            scanf("%d%d%d",&a,&b,&c);
            v.push_back(node(a,a+b,c));
        }
        sort(v.begin(),v.end(),cmp);
        dp.clear();dp.resize(N);
        dp[0]=v[0].cost;
        for(int i=1;i<N;i++) {
            int z=get(v[i].s);
            //cout<<"z= "<<z<<endl;
            if(z!=-1) dp[i]=v[i].cost+dp[z];
            else dp[i]=v[i].cost;
        }
        printf("%d\n",*max_element(dp.begin(),dp.end()));
    }
    return 0;
}
