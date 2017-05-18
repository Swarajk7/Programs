#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin>>n;
    char c[1005];
    scanf("%s",c);
    for(int i=0;i<strlen(c);i++) {
        if(c[i]=='W') n=n*2 + 11;
        else n = (n&1)+(n/2);
    }
    cout<<n<<endl;
    return 0;
}
