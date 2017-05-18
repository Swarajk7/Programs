#include <bits/stdc++.h>
using namespace std;
#define LVL 11
#define MAXN 1010
int h[MAXN];
int PAR[MAXN][LVL];
vector<int> T[MAXN];
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
		T[i].clear();
		for(int j=0;j<LVL;j++) PAR[i][j]=-1;
	}
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int t1=1;t1<=t;t1++) {
		cout<<"Case "<<t1<<":\n";
		int N,a,b,q;
		cin>>N;
		clear(N);
		for(int i=0;i<N;i++) {
			cin>>a;
			for(int j=0;j<a;j++) {
				cin>>b;
				b--;
				T[i].push_back(b);
				T[b].push_back(i);
			}
		}
		bfs(0);
		/*for(int i=0;i<N;i++) {
			cout<<h[i]<<"##";
			for(int j=0;j<LVL;j++) cout<<PAR[i][j]<<" ";
			cout<<endl;
		}*/
		cin>>q;
		while(q--) {
			cin>>a>>b;a--;b--;
			cout<<LCA(a,b)+1<<endl;
		}
	}
	return 0;
}