#include<bits/stdc++.h>
using namespace std;
char ar[8][8];
bool ok(int i,int j) {
    return i>=0 && i<8 && j>=0 && j<8;
}
int killK(int i,int j) {
    int cnt=0;
    if(ok(i+1,j) && ar[i+1][j]!='*') cnt++;
    if(ok(i-1,j) && ar[i-1][j]!='*') cnt++;
    if(ok(i,j+1) && ar[i][j+1]!='*') cnt++;
    if(ok(i,j-1) && ar[i][j-1]!='*') cnt++;
    if(ok(i+1,j+1) && ar[i+1][j+1]!='*') cnt++;
    if(ok(i+1,j-1) && ar[i+1][j-1]!='*') cnt++;
    if(ok(i-1,j+1) && ar[i-1][j+1]!='*') cnt++;
    if(ok(i-1,j-1) && ar[i-1][j-1]!='*') cnt++;
    return cnt;
}
int killR(int x,int y) {
    int i,j;
    i=x-1;j=y;
    int cnt=0;
    while(i>=0) {
        if(ar[i][j]!='*') {
            cnt++;break;
        }
        i--;
    }
    i=x+1;j=y;
    while(i<8) {
        if(ar[i][j]!='*') {
            cnt++;break;
        }
        i++;
    }
    i=x;j=y-1;
    while(j>=0) {
        if(ar[i][j]!='*') {
            cnt++;break;
        }
        j--;
    }
    i=x;j=y+1;
    while(j<8) {
        if(ar[i][j]!='*') {
            cnt++;break;
        }
        j++;
    }
    //cout<<x<<" "<<y<<" "<<cnt<<endl;
    return cnt;
}
int killB(int x,int y) {
    int i,j,cnt=0;
    i=x-1,j=y-1;
    while(i>=0 && j>=0) {
        if(ar[i][j]!='*') {
            cnt++;break;
        }
        i--;j--;
    }
    i=x-1;j=y+1;
    while(i>=0 && j<8) {
        if(ar[i][j]!='*') {
            cnt++;break;
        }
        i--;j++;
    }
    i=x+1;j=y-1;
    while(i<8 && j>=0) {
        if(ar[i][j]!='*') {
            cnt++;break;
        }
        i++;j--;
    }
    i=x+1;j=y+1;
    while(i<8 && j<8) {
        if(ar[i][j]!='*') {
            cnt++;break;
        }
        i++;j++;
    }
    return cnt;
}
int killQ(int x,int y) {
    return killB(x,y)+killR(x,y);
}
int killN(int i,int j) {
    int cnt=0;
    if(ok(i+1,j+2) && ar[i+1][j+2]!='*') cnt++;
    if(ok(i+1,j-2) && ar[i+1][j-2]!='*') cnt++;
    if(ok(i-1,j+2) && ar[i-1][j+2]!='*') cnt++;
    if(ok(i-1,j-2) && ar[i-1][j-2]!='*') cnt++;
    if(ok(i+2,j+1) && ar[i+2][j+1]!='*') cnt++;
    if(ok(i-2,j+1) && ar[i-2][j+1]!='*') cnt++;
    if(ok(i+2,j-1) && ar[i+2][j-1]!='*') cnt++;
    if(ok(i-2,j-1) && ar[i-2][j-1]!='*') cnt++;
    return cnt;
}
int killP(int i,int j) {
    int cnt=0;
    if(ok(i+1,j+1) && ar[i+1][j+1]!='*') cnt++;
    if(ok(i+1,j-1) && ar[i+1][j-1]!='*') cnt++;
    return cnt;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int t1=1;t1<=t;t1++) {
        scanf("%d",&n);
        for(int i=0;i<8;i++) {
            for(int j=0;j<8;j++) ar[i][j]='*';
        }
        string s;
        for(int i=0;i<n;i++) {
            cin>>s;
            int x=s[0]-'A';
            int y=s[1]-'1';
            char z=s[3];
            ar[x][y]=z;
        }
        int ans=0;
        for(int i=0;i<8;i++) {
            for(int j=0;j<8;j++) {
                switch(ar[i][j]) {
                case 'K':
                    ans+=killK(i,j);
                    break;
                case 'R':
                    ans+=killR(i,j);
                    break;
                case 'Q':
                    ans+=killQ(i,j); break;
                case 'B':
                    ans+=killB(i,j); break;
                case 'P':
                    ans+=killP(i,j); break;
                case 'N':
                    ans+=killN(i,j); break;
                }
            }
        }
        printf("Case #%d: %d\n",t1,ans);
    }
    return 0;
}
