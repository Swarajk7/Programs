#include <bits/stdc++.h>
using namespace std;
#define SET(x) memset(x, -1, sizeof(x))
#define CLR(x) memset(x, 0, sizeof(x))
#define MAX 105

vector < int > edges[MAX];
bool visited[MAX];
int Left[MAX], Right[MAX];

bool dfs(int u) {
    if(visited[u]) return false;
    visited[u] = true;
    int len = edges[u].size(), i, v;
    for(i=0; i<len; i++) {
        v = edges[u][i];
        if(Right[v]==-1) {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    for(i=0; i<len; i++) {
        v = edges[u][i];
        if(dfs(Right[v])) {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    return false;
}

int match() {
    SET(Left);
    SET(Right);
    int i, ret = 0;
    bool done;
    do {
        done = true;
        CLR(visited);
        for(i=0; i<MAX; i++) {
            if(Left[i]==-1 && dfs(i)) {
                done = false;
            }
        }
    } while(!done);
    for(i=0; i<MAX; i++) ret += (Left[i]!=-1);
    return ret;
}

int main() {
    int t,n,c,a,b;
    cin>>t;
    while(t--) {
        cin>>n>>c;
        for(int i=0;i<MAX;i++) edges[i].clear();
        scanf("%d",&a);
        while(a!=-1) {
            scanf("%d",&b);
            a--;b--;
            edges[a].push_back(b);
            scanf("%d",&a);
        }
        cout<<match()<<endl;;
    }
    return 0;
}
