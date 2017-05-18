#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        float x=log2(n);
        if(x==(int)x) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
