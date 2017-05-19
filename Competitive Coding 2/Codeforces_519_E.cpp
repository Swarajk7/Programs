//problem URL http://codeforces.com/problemset/problem/519/E
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
#define MAXN 100010
#define LVL 17
#define inf 1e8
int h[MAXN];
int PAR[MAXN][LVL];
int sz[MAXN];
vector<int> T[MAXN];
/*LCA for distance*/
void bfs(int node) {
	queue<pair<int,int>> q;
	h[node]=0;
	q.push(make_pair(node,-1));
	int par;
	while(!q.empty()) {
		pair<int,int> p = q.front();
		q.pop();
		node = p.first;
		par = p.second;
		//cout<<node<<" "<<par<<endl;
		PAR[node][0] = par;
		if(par+1) h[node] = h[par]+1;
		for(int i=1;i<LVL;i++) {
			if(PAR[node][i-1]+1) {
				PAR[node][i]=PAR[PAR[node][i-1]][i-1];
			}
		}
		for(int i : T[node]) {
			if(h[i]==-1)
				q.push(make_pair(i,node));
		}
	}
}
int LCA(int u,int v) {
	if(h[v]<h[u]) {
		v = u + v;
		u = v - u;
		v = v - u;
	}
	for(int i=LVL-1;i>=0;i--) {
		if(PAR[v][i]+1 && h[PAR[v][i]]>=h[u])
			v = PAR[v][i];
	}
	// now h[v] = h[u]
	if(v == u)
		return v;
	for(int i = LVL - 1;i >= 0;i --)
		if(PAR[v][i] - PAR[u][i])
			v = PAR[v][i], u = PAR[u][i];
	return PAR[v][0];
}
int dist(int u,int v) {
    return h[u]+h[v]-2*h[LCA(u,v)];
}
void dfs(int u,int par=-1) {
    sz[u]=1;
    for(int i:T[u]) {
        if(i-par) {
            dfs(i,u);
            sz[u] += sz[i];
        }
    }
}
void clear(int N) {
	for(int i=0;i<N+1;i++) {
		h[i]=-1;
		T[i].clear();
		for(int j=0;j<LVL;j++) PAR[i][j]=-1;
	}
}
int get_immidiate_child(int a,int b,int d) {
    int oa=a;
    for(int i=LVL-1;i>=0;i--) {
        //cout<<i<<" "<<PAR[a][i]<<" "<<a<<" "<<d<<" "<<dist(PAR[a][i],a)<<"$"<<endl;
        if(PAR[a][i]+1 && dist(PAR[a][i],oa) < d)
            a = PAR[a][i];
    }
    return a;
}
int query(int a ,int b) {
    int t = dist(a,b);
    if(a==b) return sz[0];
    if(t&1) return 0;
    int v = LCA(a,b);
    int t1 = dist(a,v),t2=dist(b,v);
    if(t1==t2) {
        a = get_immidiate_child(a,v,dist(a,v));
        b = get_immidiate_child(b,v,dist(b,v));
        return sz[0] - sz[a] - sz[b];
    } else {
        if(h[a]<h[b]) {
            a = a+b;
            b = a-b;
            a = a-b;
        }
        int d = dist(a,b)/2;
        a = get_immidiate_child(a,b,d);
        // a is the node just below mid point in the path from midpoint to a
        return sz[PAR[a][0]] - sz[a];
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    int m,n,a,b,t;
    cin>>n;
    clear(n);
    for(auto i=0;i<n-1;i++) {
        cin>>a>>b;
        a--;b--;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    cin>>m;
    dfs(0);
    bfs(0);
    while(m--) {
        cin>>a>>b;
        a--;b--;
        cout<<query(a,b)<<endl;
    }
    return 0;
}