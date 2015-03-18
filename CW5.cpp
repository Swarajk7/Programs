#include<bits/stdc++.h>
using namespace std;
bool ar[10][10];
void b(int x,int y) {
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(abs(i-x)==abs(j-y)) {
                ar[i][j]=true;
            }
        }
    }
}
void r(int x,int y) {
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(i==x || j==y) {
                ar[i][j]=true;
            }
        }
    }
}
void q(int x,int y) {
    r(x,y);
    b(x,y);
}
bool ok(int a,int b) {
    return a>=0 &&a <8 && b>=0 && b<8;
}
void ss(int x,int y) {
    if(ok(x+1,y)) ar[x+1][y]=true;
    if(ok(x+1,y+1)) ar[x+1][y+1]=true;
    if(ok(x+1,y-1)) ar[x+1][y-1]=true;
    if(ok(x-1,y)) ar[x-1][y]=true;
    if(ok(x-1,y+1)) ar[x-1][y+1]=true;
    if(ok(x-1,y-1)) ar[x-1][y-1]=true;
    if(ok(x,y+1)) ar[x][y+1]=true;
    if(ok(x,y-1)) ar[x][y-1]=true;
}
bool check(int x,int y) {
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(i==x && j==y) continue;
            if(abs(i-x)==1 && (abs(j-y)==1 || abs(j-y)==0)) {
                //cout<<i<<" "<<j<<endl;
                if(!ar[i][j]) return true;
            }
            else if(abs(j-y)==1 && (abs(i-x)==1 || abs(i-x)==0)) {
                //cout<<i<<" "<<j<<endl;
                if(!ar[i][j]) return true;
            }
        }
    }
    return false;
}
int main()
{
    string s;
    int x,y;
    for(int ii=0;ii<8;ii++) {
        cin>>s;
        for(int i=0;i<8;i++) {
            //cout<<s[i];
            if(s[i]=='Q') q(ii,i);
            else if(s[i]=='R') r(ii,i);
            else if(s[i]=='B') b(ii,i);
            else if(s[i]=='S') ss(ii,i);
            else if(s[i]=='P') {
                x=ii;
                y=i;
            }
        }
        //cout<<endl;
    }
    /*for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) cout<<ar[i][j]<<" ";cout<<endl;
    }
    cout<<x<<" "<<y<<endl;*/
    if(check(x,y)) cout<<"NOT YET!";
    else cout<<"CHECKMATE!";
}
