#include<bits/stdc++.h>
using namespace std;
bool dp[5][10005],mem[5][10005];
int ar[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
int get(char a) {
    return a-'i'+2;
}
void clearDP(int L) {
    for(int i=2;i<5;i++) {
        for(int j=0;j<L;j++) {
            dp[i][j]=false;
            mem[i][j]=false;
        }
    }
}
bool F(int req,int ind,string &s) {
    int cur=1;
    if(req>4) return false;
    if(mem[req][ind]) return dp[req][ind];
    while(ind<s.length()) {
        int sign=1;
        if(cur<0) sign=-1;
        cur=sign*ar[abs(cur)][get(s[ind])];
        if(cur==req) {
            int val=F(req+1,ind+1,s);
            if(val) {
                mem[req][ind]=true;
                dp[req][ind]=true;
                return true;
            }
        }
        ind++;
    }
    bool ans=false;
    if(cur==req && req==4) ans=true;
    dp[req][ind]=ans;
    mem[req][ind]=true;
    return ans;
}
bool F1(int req,int ind,string &s) {
    int k=get(s[0]);
    dp[k][0]=true;

}
int main() {
    int t,L,X;
    time_t ti = time(0);
    cout<< ti<<endl;
    scanf("%d",&t);
    for(int t1=1;t1<=t;t1++) {
        scanf("%d%d",&L,&X);
        clearDP(L*X);
        string z,s;
        cin>>z;
        for(int i=0;i<X;i++) s+=z;
        if(F(2,0,s)) printf("Case #%d: YES\n",t1);
        else printf("Case #%d: NO\n",t1);
    }
    time_t ti2 = time(0);
    cout<< ti2-ti <<endl;
    return 0;
}
