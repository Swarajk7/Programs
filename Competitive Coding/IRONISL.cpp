#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int ar[1002][1002];
void print(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) cout<<ar[i][j]<<" ";
        cout<<endl;
    }
}
int bfs(int s,int n) {
    queue<int> q;
    vector<bool> vis(n,false);
    q.push(s);
    q.push(-1);
    int dist=0;
    int ans=0;
    while(!q.empty()) {
        int x=q.front();
        q.pop();
        if(x==-1) {
            if(!q.empty()) q.push(-1);
            dist++;continue;
        }
        if(vis[x]) continue;
        vis[x]=true;
        ans+=dist;
        for(int i=0;i<n;i++) {
            if(!vis[i] && ar[x][i]) q.push(i);
        }
    }
    return ans;
}
int main()
{
    int t,n,q,v,m,x,y;
    std::ios::sync_with_stdio(false);
    cin>>t;
    string s;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) {
            cin>>s;
            for(int j=0;j<n;j++) {
                if(s[j]=='0') ar[i][j]=0;
                else ar[i][j]=1;
            }
        }
        cin>>q;
        while(q--) {
            cin>>v>>m;
            while(m--) {
                cin>>x>>y;x--;y--;
                ar[x][y]=1-ar[x][y];
            }
            //print(n);
            cout<<bfs(v-1,n)<<endl;
        }
    }
}
