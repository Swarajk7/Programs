#include<iostream>
#include<algorithm>
using namespace std;
int comp (const void * elem1, const void * elem2) {
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f < s) return  1;
    if (f > s) return -1;
    return 0;
}
long long beauty(long int *x,long int n,int p)
{
    int i;
    qsort (x, n, 4, comp);
    int w=1;
    long long bn=0;
    for(i=0;i<n;i++)
    {
       // cout<<x[i]<<" ";
        if(i+1>w)
        {
            w<<=2;
            p--;
        }
        bn+=x[i]*(long long)(p);
       // cout<<p<<" "<<bn<<endl;
    }
    return bn;
}
int fun(long n)
{
    int c=1;
    while(n!=1)
    {
        n=n/4;
        c++;
    }
    return c;
}
int main()
{
    long n,i;
    long *a;
    std::ios::sync_with_stdio(false);
    cin>>n;
    a=(long *)malloc(sizeof(long)*n);
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<beauty(a,n,fun(n));
}
