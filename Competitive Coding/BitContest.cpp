#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int arr[10005];
int main(){
    ll n,val;
    ll ans = 0;
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    ans = arr[0];
    for(int i=1;i<n;i++)
        ans = ans^arr[i];
    int cnt = 0;
    while(ans){
        if(ans&1)
            cnt++;
        ans>>=1;
    }
    if(cnt&1)
        printf("Shaka :)\n");
    else
        printf("The other player :(\n");
    return 0;
}
