#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    double ds,dt,d;
    cin>>t;
    while(t--) {
        cin>>ds>>dt>>d;
        if (dt>=d+ds) printf("%lf\n",dt-(ds+d));
        else if(ds>=d+dt)  printf("%lf\n",ds-(d+dt));
        else if(d<=ds+dt) printf("0.0\n");
        else printf("%lf\n",d-(ds+dt));
    }
    return 0;
}
