#include<bits/stdc++.h>
using namespace std;
int a1[105][105],a2[105][105];
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&T);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                scanf("%d",&a1[i][j]);
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                scanf("%d",&a2[i][j]);
            }
        }
        for(int k=0;k<n;k++) {for(int i=0;i<n;i++) {for(int j=0;j<n;j++) {a1[i][j]=min(a1[i][j],a1[i][k]+a1[k][j]);} }}
        for(int k=0;k<n;k++) {for(int i=0;i<n;i++) {for(int j=0;j<n;j++) {a1[i][j]=min(a2[i][j],a2[i][k]+a2[k][j]);} }}
        vector< pair<int,int> > v;
        for(int i=0;i<n;i++)
    }
}
