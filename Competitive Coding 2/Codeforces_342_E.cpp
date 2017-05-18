//problem URL http://codeforces.com/problemset/problem/342/E
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
#define MAXN 100010
#define LVL 17
#define inf 1e8
int h[MAXN];
int PAR[MAXN][LVL];
int sz[MAXN];
int dcpar[MAXN];
int ans[MAXN];
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
void clear(int N) {
	for(int i=0;i<N+1;i++) {
		h[i]=-1;
		dcpar[i]=-1;
		ans[i] = inf;
		T[i].clear();
		for(int j=0;j<LVL;j++) PAR[i][j]=-1;
	}
}
int dist(int u,int v) {
    return h[u]+h[v]-2*h[LCA(u,v)];
}
/*Centroid Decomposition*/
void dfs_updatesize(int node,int p,int &nn) {
    sz[node] = 1;
    nn++;
    for(auto i:T[node]) {
        if(i-p) {
            dfs_updatesize(i,node,nn);
            sz[node]+=sz[i];
        }
    }
}
int find_centroid(int node,int p,int nn) {
    int x=nn/2;
    for(auto i:T[node]) {
        if(i-p) {
            if(sz[i]>x) return find_centroid(i,node,nn);
        }
    }
    return node;
}
void decompose(int node,int par) {
    int nn=0;
    dfs_updatesize(node,-1,nn);
    int centroid = find_centroid(node,-1,nn);
    dcpar[centroid]=par;
    for(auto it=T[centroid].begin();it!=T[centroid].end();it++) {
        T[*it].erase(std::remove(T[*it].begin(), T[*it].end(), centroid), T[*it].end());
        decompose(*it,centroid);
    }
    T[centroid].clear();
}
/*Querying Centroid Decomposition*/
void updateColor(int u) {
    int x=u;
    ans[u] = 0;
    while(x!=-1) {
        ans[x] = min(ans[x],dist(x,u));
        x = dcpar[x];
    }
}
int getNearestDistance(int u) {
    int x=u,_ans=inf;
    while(x!=-1) {
        _ans = min(_ans,ans[x]+dist(x,u));
        x=dcpar[x];
    }
    return _ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int m,n,a,b,t,v;
    cin>>n>>m;
    clear(n);
    for(auto i=0;i<n-1;i++) {
        cin>>a>>b;
        a--;b--;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    bfs(0);
    decompose(0,-1);
    //for(int i=0;i<n;i++) cout<<dcpar[i]<<" ";
    updateColor(0);
    while(m--) {
        cin>>t>>v;
        v--;
        if(t==1) {
            updateColor(v);
        } else {
            cout<<getNearestDistance(v)<<endl;
        }
    }
    return 0;
}
