#include<bits/stdc++.h>
using namespace std;
#define MAX 20
int arr[MAX][MAX];
#define FOR(x,n) for(int x=0;x<n;x++)
int main()
{
    int n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) cin>>ar[i][j];
    }
    FOR(k,n) {
        FOR(i,n) {
            FOR(j,n) {
                ar[i][j]=min(ar[i][j],ar[i][k]+ar[k][j]);
            }
        }
    }
    FOR(i,n) {FOR(j,n) { cout<<ar[i][j]<<" ";} cout<<endl;}
    return 0;
}
