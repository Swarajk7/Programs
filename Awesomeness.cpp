#include<bits/stdc++.h>
#include<cstring>
using namespace std;
typedef long long llong;
const int MAXN = 500020;
int tree[MAXN];
int read(int idx){
 int sum = 0;
 while (idx > 0){
  sum += tree[idx];
  idx -= (idx & -idx);
 }
 return sum;
}
void update(int idx ,int val){
 while (idx <= MAXN){
  tree[idx] += val;
  idx += (idx & -idx);
 }
}
int main()
{
    char s[MAXN];
    scanf("%s",s);
    std::transform(s, s+strlen(s), s, ::tolower);
    for(int i=0;i<strlen(s)-10;i++) {
        int h=0,a=0,c=0,k=0,e=0,r=0,t=0;
        for(int j=0;j<11;j++) {
            if(s[j+i]=='h') h++;if(s[j+i]=='a') a++;if(s[j+i]=='e') e++;if(s[j+i]=='r') r++;if(s[j+i]=='t') t++;
            if(s[j+i]=='k') k++; if(s[j+i]=='c') c++;
        }
        if(a==2 && h==2 && c==1 && k==1 && e==2 && r==2 && t==1) update(i+1,1);
    }
    int q,l,r;
    scanf("%d",&q);
    while(q--) {
        scanf("%d%d",&l,&r);
        int ans=0;
        if(r<11) ans=0;
        else {
            if(r-10>=l) {ans=ans+read(r-10);
            if(l!=1) ans=ans-read(l-1);}
        }
        cout<<ans<<endl;
    }
    return 0;
}
