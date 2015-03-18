#include<bits/stdc++.h>
using namespace std;
#define MAX 400005
int a[MAX],b[MAX];
int main() {
    int t;
    int n,d;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++) {
            scanf("%d",&b[i]);
        }
        scanf("%d",&d);
        int minVal=INT_MAX,minIndex;
        for(int i=0;i<n;i++) {
            int x=(int)ceil((d-a[i]*1.0)/(a[i]-b[i]));
            int y=(a[i]+b[i])*x+(d-(a[i]*x-b[i]*x));
            if(d<a[i]) y=d;
            if(y<minVal) {
                minIndex=i;
                minVal=y;
            }
            //cout<<y<<endl;
        }
        printf("%d\n",minIndex+1);
    }
    return 0;
}
