#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,a;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        vector<int> v(m);
        for(int i=0;i<m;i++) {
            scanf("%d",&a);v[i]=a;
        }
        int mn=*min_element(v.begin(),v.end());
        int mx=*max_element(v.begin(),v.end());
        for(int i=0;i<n;i++) {
            printf("%d ",max(abs(i-mn),abs(i-mx)));
        }
        printf("\n");
    }
    return 0;
}
