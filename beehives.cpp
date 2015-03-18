#include <bits/stdc++.h>
using namespace std;
bool visit[505];
vector< pair<int,int> > G[505];
int n,m;
int ans,start;
/*void dfs(int u,int len){
  //cout << u << len << endl;
  if(visit[u] && u!=start)
    return;
  if(visit[u] && u==start){
    if(len>3)ans = min(ans,len-1);
    return;
  }
  visit[u] = true;
  for(int i=0;i<G[u].size();i++){
     //if(!visit[G[u][i]])
        dfs(G[u][i],len+1);
  }
  visit[u] = false;
}
void solve(){
  for(int i=0;i<n;i++){
      memset(visit,false,sizeof visit);
      start = i;
      dfs(i,1);
  }
}*/
/*int dp[505];
void solve(){
  memset(dp,-1,sizeof dp);
  for(int i=0;i<n,i++){

  }
}*/
struct comp{
bool opertor(){

}
};
priority_queue< pair<int,int> ,vector< pair<int,int> > ,comp > PQ;
int main(){
int t,u,v;
scanf("%d",&t);
int cas = 0;
while(t--){
    cas++;
    ans = INT_MAX;
   scanf("%d %d",&n,&m);
   while(m--){
    scanf("%d %d",&u,&v);
    G[u].push_back(make_pair(v,1));
    G[v].push_back(make_pair(u,1));
   }
   solve();
    if(ans==INT_MAX)
        printf("Case %d: impossible\n",cas);
    else
   printf("Case %d: %d\n",cas,ans);
   for(int i=0;i<505;i++)
     G[i].clear();
    Q.clear();
}
return 0;
}
