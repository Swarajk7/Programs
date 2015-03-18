#include<bits/stdc++.h>
using namespace std;
#define MAX 130
int ar[MAX][MAX];
int up[MAX][MAX][MAX];
int down[MAX][MAX][MAX];
int lenD[MAX][MAX],lenU[MAX][MAX];
void procD(int x,int y,int n,int m) {
    int i=x,j=y;
    int l=1;
    int val=0;
    while(i<n && j<m) {
        down[x][y][l]=val+ar[i][j];
        val=down[x][y][l];
        i++;
        j++;
        l++;
    }
    lenD[x][y]=l-1;
}
void procT(int x,int y,int n,int m) {
    int i=x,j=y;
    int l=1;
    int val=0;
    while(i<n && j<m) {
        up[x][y][l]=val+ar[i][j];
        val=up[x][y][l];
        i--;
        j++;
        l++;
    }
    lenU[x][y]=l-1;
}
int getAns(int x,int y,int n,int m) {
    int i=x,j=y;
    int len=lenD[x][y];
    int mx=INT_MIN;
    for(int l=2;l<=len;l++) {
        int ans=down[x][y][l];
        if(lenU[x+l-1][y]<l) break;
        ans+=up[x+l-1][y][l];
        if(l&1) {
            int k=l/2;
            ans-=ar[x+k ][y+k];
        }
        mx=max(mx,ans);
    }
    return mx;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                scanf("%d",&ar[i][j]);
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                procD(i,j,n,m);
                procT(i,j,n,m);
            }
        }
        /*for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) cout<<up[i][j][3]<<" ";cout<<endl;
        }*/
        int mx=INT_MIN;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int p=getAns(i,j,n,m);
                mx=max(mx,p);
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
