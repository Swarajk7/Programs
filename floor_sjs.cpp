#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <map>
#define ull long long

using namespace std;
ull powModM(ull a,ull b,ull m)
{
    if(b==0)
        return 1;
    ull temp=powModM(a,b/2,m);
    if(b%2)
        return (((temp*temp)%m)*a)%m;
    else
        return (temp*temp)%m;
}


ull calcFun1(ull N,ull M1)
{
    ull ans=0;
    ull N1=N%M1;
   ans=((6*powModM(N1,5,M1))%M1+(15*powModM(N1,4,M1))%M1+(10*powModM(N1,3,M1))%M1+(-N1+M1)%M1)%M1;
    return ans;
}

int main()
{
  //  freopen("inp_6.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        ull N,M,ansFinal=0;
        cin>>N>>M;
        ull i,sqrtN,coeff;
        M*=30;
        for(i=1;i*i<=N;i++){
            ull temp2=calcFun1(N/i,M);
            ansFinal=(ansFinal+temp2)%M;
        }
        ansFinal/=30;
        M/=30;
        sqrtN=i-1;
        i=1;
        ull t1;
        while(1){
            coeff=N/i-sqrtN;
            if(coeff<=0)
                break;
            t1=(i*i)%M;
            ansFinal=(ansFinal + coeff*((t1*t1)%M))%M;
            i++;
        }
        cout<<ansFinal<<endl;
    }
}
