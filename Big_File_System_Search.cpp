#include<bits/stdc++.h>
using namespace std;
class File {
    map<int,int> mp;
    int k;
public:
    File() {
        k=0;
    }
    void ins(int a) {
        k++;
        if(mp.find(a)==mp.end()) mp[a]=1;
        else mp[a]+=1;
    }
    int get(int a) {
        if(mp.find(a)==mp.end()) return 0;
        else return mp[a];
    }
    bool queryTemp(File f) {
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++) {
            if(f.get(it->first)!=it->second) return false;
        }
        return true;
    }
    bool query2(File f) {
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++) {
            if(f.get(it->first)!=0) return true;
        }
        return false;
    }
    bool query3(File f) {
        if(query2(f)) {
            if(!queryTemp(f)) return true;
            else return false;
        }
        return false;
    }
    bool query1(File f) {
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++) {
            if(f.get(it->first)<it->second) return false;
        }
        return true;
    }
};
int main() {
    int n,m,a,k,q,t;
    scanf("%d",&n);
    vector<File> v(n);
    for(int i=0;i<n;i++) {
        scanf("%d",&m);
        while(m--) {
            scanf("%d",&a);
            v[i].ins(a);
        }
    }
    scanf("%d",&q);
    while(q--) {
        scanf("%d",&t);
        File f;
        scanf("%d",&k);
        while(k--) {
            scanf("%d",&a);
            f.ins(a);
        }
        int ans=0;
        switch(t) {
            case 1: for(int i=0;i<n;i++) if(f.query1(v[i])) ans++; break;
            case 2: for(int i=0;i<n;i++) if(v[i].query2(f)) ans++; break;
            case 3: for(int i=0;i<n;i++) if(v[i].query3(f)) ans++; break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
