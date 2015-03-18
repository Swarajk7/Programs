#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<vector>
using namespace std;
map<int,int> mp;
vector<int> prime;
int map_push(int n,int cnt) {
    //cout<<n<<" "<<cnt<<endl;
    if(mp.find(n)==mp.end()) mp[n]=cnt;
    else mp[n]=max(mp[n],cnt);
}
void prime_fact(int n) {
    for(int i=0;i<prime.size();i++) {
        if(n%prime[i]==0) {
            int cnt=0;
            //cout<<prime[i]<<endl;
            while(n%prime[i]==0) {
                cnt++;
                n/=prime[i];
            }
            map_push(prime[i],cnt);
        }
    }
}
int main()
{
    int t,n,a;
    scanf("%d",&t);
    vector<bool> sieve(1005);
    for(int i=2;i<sieve.size();i++) {
        if(sieve[i]) continue;
        for(int j=i+i;j<sieve.size();j+=i) {
            sieve[j]=true;
        }
    }
    for(int i=2;i<sieve.size();i++) {
        if(!sieve[i]) {
            prime.push_back(i);
            //cout<<i<<endl;
        }
    }
    while(t--) {
        scanf("%d",&n);
        mp.clear();
        for(int i=0;i<n;i++) {
            scanf("%d",&a);
            prime_fact(a);
        }
        int ans=0;
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++) {
            ans+=it->second;
            //cout<<it->second<<endl;
        }
        printf("%d\n",ans);
    }
    return 0;
}
