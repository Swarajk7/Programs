#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
vector<ll> v;
vector<int> seg;
int build_helper(int l,int r,int index)
{
    if(l==r)
    {
        seg[index]=l;
        return l;
    }
    int mid=(l+r)/2;
    int left=build_helper(l,mid,2*index+1);
    int rr=build_helper(mid+1,r,2*index+2);
    if(v[left]<=v[rr]){
        seg[index]=left;
        return left;
    }
    else {
        seg[index]=rr;
        return rr;
    }
}
void build(int n)
{
    build_helper(0,n-1,0);
}
int query_help(int sl,int sr,int l,int r,int index)
{
    //printf("%d %d %d\n",l,r,index);
    if(l>sr || r<sl) return -1;
    if(l==r) return l;
    if(l>=sl && r<=sr) return seg[index];
    else
    {
        int mid=(l+r)/2;
        int left=query_help(sl,sr,l,mid,2*index+1);
        int right=query_help(sl,sr,mid+1,r,2*index+2);
        if(left==-1) return right;
        else if(right==-1) return left;
        else
        {
            if(v[left]<v[right]) return left;
            else return right;
        }
    }
}
int query(int l,int r,int n)
{
    int x=query_help(l,r,0,n-1,0);
    return x;
}
ll findMax_Helper(int l,int r,int n)
{
    if(l>r) return 0;
    if(l==r) return v[l];
    int minind=query(l,r,n);
    ll ans1=(r-l+1)*v[minind];
    ll ans2=findMax_Helper(l,minind-1,n);
    ll ans3=findMax_Helper(minind+1,r,n);
    ll k=max(ans1,ans2);
    return max(k,ans3);
}
ll findMax(int n)
{
    return findMax_Helper(0,n-1,n);
}
int main()
{
    int n;
    ll a;
    scanf("%d",&n);
    while(n!=0)
    {
        v.clear();
        seg.clear();
        v.resize(n);
        seg.resize(4*n,-1);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a);
            v[i]=a;
        }
        build(n);
        //for(int i=0;i<2*n;i++) cout<<seg[i]<<" ";cout<<endl;
        printf("%lld\n",findMax(n));
        scanf("%d",&n);
    }
    return 0;
}
