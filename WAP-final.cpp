#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
#include<string>
#include<map>
#include<queue>
#define MAX 120
#define INF 1e8
#define DP_MAX 1<<20
using namespace std;
int dp[DP_MAX][20];
class Orienteering {
    vector< vector<int> > v;
    string s[MAX];
    int n,h,w;
    vector< vector<bool> > visit;
    map< pair<int,int> , int > m;
    bool connection_failed,input_error;
    void BuildGraph();
    void take_input();
    void BFS(int,int);
    int TSP(int,int);
    bool isValid(int,int);
    bool isInputValid();
    int Solve();
public:
    Orienteering() { connection_failed=false; input_error=false; }
    void main();
};
void Orienteering::main() {
    take_input();
    BuildGraph();
    cout<<Solve();
}
int main(int argc,char *argv[]) {
    Orienteering o;
    o.main();
    return 0;
}
void Orienteering::take_input() {
    scanf("%d%d",&w,&h);
    for(int i=0;i<h;i++)
            cin>>s[i];
    if(!isInputValid()) input_error=true;
}
void Orienteering::BuildGraph() {
    //cout<<h<<w<<endl;
    int x=-1,y=-1;
    int cnt=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            //cout<<s[i][j];
            if(s[i][j]=='S') m[make_pair(i,j)]=0;
            else if(s[i][j]=='G') {
                x=i;
                y=j;
            }
            else if(s[i][j]=='@') m[make_pair(i,j)]=++cnt;
        }
        //cout<<endl;
    }
    if(x==-1 || y==-1) ; //Error
    else m[make_pair(x,y)]=++cnt;
    cnt++;
    v.resize(cnt, vector<int>(cnt,-1));
    n=cnt;
    for(map< pair<int,int> ,int>::iterator it = m.begin(); it != m.end(); ++it) {
        pair<int,int> p=it->first;
        BFS(p.first,p.second);
        //cout<<"{"<<p.first<<","<<p.second<<"}: "<<it->second<<endl;
    }
    //n=cnt;
    for(int i=0;i<n;i++)
    {
        //cout<<v[i][0]<<" ";
        if(v[i][0]==-1) connection_failed=true;
        v[i][0]=((i==n-1 || i==0)?0:INF);
    }
}
void Orienteering::BFS(int x,int y) {
    //cout<<"Called\n";
    typedef pair<int,int> pii;
    pii thisone=make_pair(x,y);
    queue<pii> q;
    q.push(thisone);
    //cout<<thisone.first<<" "<<thisone.second<<endl;
    q.push(make_pair(-1,-1));
    int dist=0;
    visit.clear();
    visit.resize(h,vector<bool>(w,false));
    while(!q.empty())
    {
        pii p=q.front();
        q.pop();
        //cout<<p.first<<" "<<p.second<<endl;
        int x1=p.first,y1=p.second;
        if(x1==-1 && y1==-1) {
            //cout<<dist<<endl;
            if(!q.empty()) {
                q.push(make_pair(-1,-1));
                dist++;
            }
        }
        else {
            if(visit[x1][y1]) continue;
            if(s[x1][y1]!='.') {
                v[m[p]][m[thisone]]=dist;
                v[m[thisone]][m[p]]=dist;
            }
            visit[x1][y1]=true;
            if(isValid(x1+1,y1)) q.push(make_pair(x1+1,y1));
            if(isValid(x1-1,y1)) q.push(make_pair(x1-1,y1));
            if(isValid(x1,y1+1)) q.push(make_pair(x1,y1+1));
            if(isValid(x1,y1-1)) q.push(make_pair(x1,y1-1));
        }
    }
}
bool Orienteering:: isValid(int a,int b)
{
    //cout<<a<<" "<<b<<endl;
    return (a>=0 && a<h && b>=0 && b<w && s[a][b]!='#') ;
}
int Orienteering::TSP(int S,int i)
{
    //if(S==0) return v[i][0];
    if(dp[S][i]!=-1) return dp[S][i];
    //cout<<S<<" "<<i<<endl;
    dp[S][i]=INF;
    for(int j=0;j<n;j++)
    {
        if(j!=i &&(S & (1<<j)))
        {
            dp[S][i]=min(dp[S][i],TSP(S&(~(1<<j)),j)+v[i][j]);
        }
    }
    return dp[S][i];
}
int Orienteering::Solve() {
    if(connection_failed || input_error) return -1;
    int S=1<<n;S-=2;
    for(int i=0;i<(1<<n);i++) {
        for(int j=0;j<n;j++) dp[i][j]=-1;
    }
    for(int i=0;i<n;i++) dp[0][i]=v[i][0];
    TSP(S,0);
    return dp[S][0];
}
bool Orienteering::isInputValid() {
    if(w<=0 || w>100) return false;
    if(h<=0 || h>100) return false;
    int no_of_s=0,no_of_g=0;
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            if(!(s[i][j]=='.' || s[i][j]=='#' || s[i][j]=='G' || s[i][j]=='S' || s[i][j]=='@')) return false;
            if(s[i][j]=='S') no_of_s++;
            else if(s[i][j]=='G') no_of_g++;
        }
    }
    return (no_of_g==1 && no_of_s==1);
}
