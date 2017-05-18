#include<iostream>
#include<cstdio>
int f(int n)
{
    //printf("%d\n",n);
    if(n<=0) return 1;
    else
    {
        return f(--n)+f(n--);
    }
}
int main()
{
    int t;
    scanf("%d",&t);

    return 0;
}
