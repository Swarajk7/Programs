#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int main()
{
    int t,n,a;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        v.clear();
        v.resize(n);
        for(int i=0;i<n;i++) {
            scanf("%d",&a);
            v[i]=a;
        }
        int k;
        scanf("%d",&k);
        int mx=-1;
        for(int i=0;i<k;i++) {
            scanf("%d",&a);
            mx=max(a,mx);
        }
        //cout<<*(v.begin()+mx);
        int xx=*min_element(v.begin(),v.begin()+mx);
        printf("%d\n",xx);
    }
    return 0;
}
