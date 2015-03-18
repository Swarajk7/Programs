#include<bits/stdc++.h>
using namespace std;
#define MAX 350
char ar[MAX][MAX];
int mem[MAX][MAX];
bool visit[MAX][MAX];
int n;
bool okstar(int i,int j) {
    if(i>=0 && i<n && j>=0 && j<n) {
        if(ar[i][j]=='*') return true;
    }
    return false;
}
bool ok(int i,int j) {
    return i>=0 && i<n && j>=0 && j<n && ar[i][j]!='*';
}
int cal(int i,int j) {
    int cnt=0;
    if(okstar(i+1,j)) cnt++;
    if(okstar(i+1,j-1)) cnt++;
    if(okstar(i+1,j+1)) cnt++;
    if(okstar(i,j-1)) cnt++;
    if(okstar(i,j+1)) cnt++;
    if(okstar(i-1,j)) cnt++;
    if(okstar(i-1,j-1)) cnt++;
    if(okstar(i-1,j+1)) cnt++;
    return cnt;
}
void dfs(int i,int j) {
    if(visit[i][j]) return;
    if(mem[i][j]!=0) {
        visit[i][j]=true;
        return;
    }
    else {
        visit[i][j]=true;
        if(ok(i+1,j)) dfs(i+1,j);
        if(ok(i+1,j-1)) dfs(i+1,j-1);
        if(ok(i+1,j+1)) dfs(i+1,j+1);
        if(ok(i,j-1)) dfs(i,j-1);
        if(ok(i,j+1)) dfs(i,j+1);
        if(ok(i-1,j)) dfs(i-1,j);
        if(ok(i-1,j-1)) dfs(i-1,j-1);
        if(ok(i-1,j+1)) dfs(i-1,j+1);
    }
}
vector< pair<int,int> > v;
int main()
{
    int t;
    cin>>t;
    for(int t1=1;t1<=t;t1++) {
        cin>>n;
        for(int i=0;i<n;i++) {
            cin>>ar[i];
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                visit[i][j]=false;
                mem[i][j]=cal(i,j);
                if(mem[i][j]==0) v.push_back(make_pair(i,j));
            }
        }
        /*for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout<<mem[i][j]<<" ";
            }
            cout<<endl;
        }*/
        int ans=0;
        for(int i=0;i<v.size();i++) {
            pair<int,int> p=v[i];
            int i1=p.first,j1=p.second;
            if(ar[i1][j1]!='*' && mem[i1][j1]==0 && visit[i1][j1]==false) {
                ans++;
                dfs(i1,j1);
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(ar[i][j]!='*' && visit[i][j]==false) ans++;
            }
        }
        printf("Case #%d: %d\n",t1,ans);
    }
    return 0;
}
