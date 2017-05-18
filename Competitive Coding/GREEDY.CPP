#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> vec[10];
/*void solve1(){
int n = a.length();
int m = b.length();
 int flag = 0;
 int mx;
    for(int i=0;i<n;i++){
       mx = b[i]-48;
       int val = a[i]-48;
       if(val<=mx){
         for(int j =0 ;j<vec[val].size();j++){
            int p = vec[val][j];
            if(p<mx) continue;
            else if(p==mx){a[i]=p+48;break;}
            else {
                a[i]=vec[val][j-1]+48;break;
            }
         }
       }
    }
}*/
void solve(string a,string b,int i) {
    int n=a.length(),m=b.length();
    if(i==n) {

    }
    int p=a[i]-48;
    for(int k=0;k<vec[p].size();k++) {
        char q=vec[p][k]+48;
        solve(a,b,i+1);
    }
}
void pre(){
    vec[0].pb(0);
vec[0].pb(8);
vec[1].pb(0);vec[1].pb(1);vec[1].pb(3);vec[1].pb(4);vec[1].pb(7);vec[1].pb(8);vec[1].pb(9);
vec[2].pb(2);vec[2].pb(8);
vec[3].pb(3);vec[3].pb(8);vec[3].pb(9);
vec[4].pb(4);vec[4].pb(8);vec[4].pb(9);
vec[5].pb(5);vec[5].pb(6);vec[5].pb(8);vec[5].pb(9);
vec[6].pb(6);vec[6].pb(8);
vec[7].pb(0);vec[7].pb(3);vec[7].pb(7);vec[7].pb(8);vec[7].pb(9);
vec[8].pb(8);
vec[9].pb(8);vec[9].pb(9);
}
int main(){
    int t,l1,l2;
    cin >> t;
    string a,b;
    pre();
    while(t--){
        cin >> a >> b;
        l1 = a.length();
        l2 = b.length();
        if(l2>l1)
            solve2();
        else
           solve1();
        cout << a << endl;
    }
    return 0;
}

