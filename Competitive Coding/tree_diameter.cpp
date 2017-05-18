#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > tree;
vector<bool> visited,del;
vector<int> mem;
int proc(int x) {
    if(del[x]) return 0;
    if(visited[x]) return 0;
    int max1=0,max2=0;
    visited[x]=true;
    for(int i=0;i<tree[x].size();i++) {
        if(!visited[tree[x][i]]) {
            int k=proc(tree[x][i]);
            if(k>max1) {
                max2=max1;
                max1=k;
            } else if(max2<k) max2=k;
        }
    }
    mem[x]=max1+max2+1;
    return max1+1;
}
int root() {
    int root=-1,rootval=-1;
    for(int i=0;i<mem.size();i++) {
        if(mem[i]>rootval) {
            rootval=mem[i];
            root=i;
        }
    }
    return root;
}
void delLeaf(int x) {
    //cout<<x<<endl;
    if(mem[x]==1) {
        del[x]=true;
        return;
    }
    int mx1=0,mx1i=-1,mx2=0,mx2i=-1;
    for(int i=0;i<tree[x].size();i++) {
        int k=tree[x][i];
        if(del[k]) continue;
        if(mem[k]>mx1) {
            mx2=mx1;
            mx2i=mx1i;
            mx1=mem[k];
            mx1i=k;
        } else if(mem[k]>mx2) {
            mx2=mem[k];
            mx2i=mem[k];
        }
    }
    int m1=pathVal(mx1i);
    int m2=pathVal(mx2i);

    mem[x]=-1;
    delLeaf(choose);
}
int main()
{
    int n,k,u,v;
    scanf("%d%d",&n,&k);
    tree.resize(n);
    del.resize(n,false);
    for(int i=0;i<n-1;i++) {
        scanf("%d%d",&u,&v);
        u--;
        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for(int i=0;i<k;i++) {
        int x=0;
        visited.clear();
        visited.resize(n,false);
        mem.clear();
        mem.resize(n,false);
        while(del[x]) x++;
        proc(x);
        //for(int i=0;i<n;i++) cout<<mem[i]<<" ";cout<<endl;
        int z=root();
        visited.clear();
        visited.resize(n,false);
        mem.clear();
        mem.resize(n,false);
        proc(z);
        cout<<z<<endl;
        delLeaf(z);
    }
    //cout<<"A";
    int x=0;
    visited.clear();
    visited.resize(n,false);
    mem.clear();
    mem.resize(n,false);
    while(del[x]) x++;
    proc(x);
    cout<<mem[root()]-1<<endl;
    return 0;
}
