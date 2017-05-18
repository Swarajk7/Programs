#include<iostream>
#include<cstdio>
using namespace std;
int B[55][55][55];
int A[55][55][55];
int main() {
    int t,n;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                for(int k=0;k<n;k++) scanf("%d",&B[i][j][k]);
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                for(int k=0;k<n;k++) {
                    //cout<<i<<" "<<j<<" "<<k<<" "<<B[i-1][j][k]<<"\n";
                    A[i][j][k]=B[i][j][k];
                    if(k>=1) A[i][j][k]-=B[i][j][k-1];
                    if(j>=1) A[i][j][k]-=B[i][j-1][k];
                    if(k>=1 && j>=1) A[i][j][k]+=B[i][j-1][k-1];
                    if(i>=1) {
                        int p=i;
                        while(p>0) {
                            A[i][j][k]-=A[p-1][j][k];
                            p--;
                        }
                    }
                    //if(j==0 && k>=1 & i>=1) A[i][j][k]+=B[i-1][j][k-1];
                    //if(j>=0 && k==0 & i>=1) A[i][j][k]+=B[i-1][j-1][k];
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                for(int k=0;k<n;k++) {
                    printf("%d ",A[i][j][k]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
