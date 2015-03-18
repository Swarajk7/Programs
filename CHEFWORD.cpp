#include<bits/stdc++.h>
using namespace std;
#define K 3
class Matrix {
    public:
    double a[K][K];
    void take_input() {
        for(int i=0;i<K;i++) {
            for(int j=0;j<K;j++) cin>>a[i][j];
        }
    }
    Matrix() {}
    Matrix (const Matrix &X) {
        for(int i=0;i<K;i++) {
            for(int j=0;j<K;j++) a[i][j]=X.a[i][j];
        }
    }
    Matrix into(Matrix B) {
        double sum = 0;
        Matrix X;
        for (int i = 0; i <= K; i++) {
          for (int j = 0; j <= K; j++) {
             sum = 0;
             for (int k = 0; k <= K; k++) {
                sum = sum + a[i][k] * B.a[k][j];
             }
             X.a[i][j] = sum;
          }
       }
        return X;
    }
};
Matrix Pow(Matrix A,int k) {
    cout<<k<<endl;
    if(k==1) return A;
    Matrix A2 = A.into(Matrix(A));
    if(k&1) return A.into(Pow(A2,k/2));
    else return Pow(A2,k/2);
}
int main()
{
    int t,n,k;
    char s[10];
    cin>>t;
    while(t--) {
        scanf("%d%d",&n,&k);
        scanf("%s",s);
        Matrix A;
        A.take_input();
        //Matrix X = Matrix(Pow(A,k));
        Matrix Z = A.into(Matrix(A));
        Matrix X = Z.into(Matrix(Z));
        for(int i=0;i<K;i++) {
            for(int j=0;j<K;j++) printf("%lf ",X.a[i][j]); cout<<endl;
        }
        break;
    }
    return 0;
}
