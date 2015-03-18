#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> v,pat;
int main()
{
    int t,n,a,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        v.resize(n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            v[i]=a;
        }
        scanf("%d",&k);
        pat.resize(k);
        for(int i=0;i<k;i++)
        {
            scanf("%d",&a);
            pat[i]=a;
        }
        int *pi=new int[k];
        int i=1,len=0;
        pi[0]=0;
        while(i<k)
        {
            if(pat[i]==pat[len])
            {
                len++;
                pi[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                {
                    len=pi[len-1];
                }
                else
                {
                    pi[i]=0;
                    i++;
                }
            }
        }
        //for(int i=0;i<k;i++) cout<<pi[i]<<" ";cout<<endl;
        i=0;
        int j=0;
        bool flag=false;
        while(i<n)
        {
            //printf("%d %d\n",v[i],pat[j]);
            if(v[i]==pat[j])
            {
                i++;
                j++;
            }
            if(j==k)
            {
                flag=true;
                break;
            }
            else if(v[i]!=pat[j]) {
                if(j!=0) j=pi[j-1];
                else i++;
            }
        }
        if(flag) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}
