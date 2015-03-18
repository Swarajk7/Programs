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
#define DP_MAX 1048576
using namespace std;
vector< vector<int> > v;
int dp[DP_MAX][20];
int n,h,w;
int G(int S,int i)
{
    if(S==0) return v[i][0];
    if(dp[S][i]!=-1) return dp[S][i];
    //cout<<S<<" "<<i<<endl;
    dp[S][i]=INF;
    for(int j=0;j<n;j++)
    {
        if(j!=i &&(S & (1<<j)))
        {
            dp[S][i]=min(dp[S][i],G(S&(~(1<<j)),j)+v[i][j]);
        }
    }
    return dp[S][i];
}
string s[MAX];
map< pair<int,int> , int > m;
int isValid(int a,int b)
{
    //cout<<w<<" "<<h<<endl;
    return (a>=0 && a<h && b>=0 && b<h && s[a][b]!='#');
}
vector< vector<bool> > visit;
void BFS(int x,int y)
{
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
void BuildGraph()
{
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
    v.resize(cnt, vector<int>(cnt,-12));
    n=cnt;
    for(map< pair<int,int> ,int>::iterator it = m.begin(); it != m.end(); ++it) {
        pair<int,int> p=it->first;
        BFS(p.first,p.second);
        //cout<<"{"<<p.first<<","<<p.second<<"}: "<<it->second<<endl;
    }
    //n=cnt;
    for(int i=0;i<n;i++)
    {
        v[i][0]=((i==n-1 || i==0)?0:INF);
    }
}
int main()
{
    //-1 wala condtion is left :(
    scanf("%d%d",&w,&h);
    for(int i=0;i<h;i++)
        cin>>s[i];
    BuildGraph();
    //v.resize(n,vector<int>(n));
    /*for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j];
        cout<<endl;
    }*/
    cout<<n<<endl;
    //dp.resize(1<<n,vector<int>(n,-1));
    int S=1<<n;S-=2;
    for(int i=0;i<(1<<n);i++) {
        for(int j=0;j<n;j++) dp[i][j]=-1;
    }
    cout<<"Y";
    G(S,0);
    /*for(int i=0;i<dp.size();i++)
    {
        for(int j=0;j<dp[i].size();j++) cout<<dp[i][j]<<" ";cout<<endl;
    }*/
    cout<<dp[S][0]<<endl;
    return 0;
}
