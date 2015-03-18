#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define uint unsigned int
uint factors(uint n)
{
    if(n==1) return 1;
    /*
    rootn=(n**0.5)
    ans=2
    val=2
    while val<rootn:
        if n%val==0:
            p=n/val
            ans+=2
        val+=1
    if rootn==val:
        ans+=1
    return ans
    */
    float rootn=sqrt(n);
    //printf("%d\n",rootn);
    uint ans=2,val=2;
    while(val<rootn)
    {
        if(n%val==0)
        {
            ans+=2;
        }
        val++;
    }
    if(rootn==val) ans++;
    return ans;
}
int main()
{
    uint t,n;
    scanf("%u",&t);
    while(t--)
    {
        scanf("%u",&n);
        printf("%u\n",factors(n));
    }
    return 0;
}
