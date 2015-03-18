#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 1000000009
class data {
public:
    int a1,d;
    data(int x,int y) {
        a1=x;
        d=y;
    }
};
vector<int> a;
bool comp(data aa,data ab) {
    int x=a[aa.a1]-aa.d*aa.a1;
    int y=a[ab.a1]-ab.d*ab.a1;
    if(x==y) {
        return aa.d<ab.d;
    }
    else return x<y;
}
void print(int start,int diff) {
     for(int i=0;i<a.size();i++) {
            printf("%d ",a[start]+(i-start)*diff);
     }
     printf("\n");
}
vector<data> v;
int main() {
    int n,k,aa;
    scanf("%d%d",&n,&k);
    a.resize(n);
    for(int i=0;i<n;i++) {
        scanf("%d",&aa);
        a[i]=aa;
    }
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(j-i-1>k) break;
            float d=(a[j]-a[i])/((j-i)*1.0);
            if(d==(int)d) {
                //cout<<i<<" "<<j<<" "<<d<<endl;
                v.push_back(data(i,(int)d));
            }
        }
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<v.size();i++) {
        int start=v[i].a1;
        int diff=v[i].d;
        int change=0;
        //cout<<"s="<<start<<"d="<<diff;
        for(int i=0;i<n;i++) {
            if(a[i]!=a[start]+(i-start)*diff) change++;
            if(change>k) break;
        }
        if(change<=k) {
            print(start,diff);
            break;
        }
    }
    return 0;
}
