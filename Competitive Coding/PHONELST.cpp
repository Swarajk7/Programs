#include<bits/stdc++.h>
using namespace std;
int total=0;
struct Trie {
    int num,prefix;
    bool flag;
    Trie() {
        num=-1;
        prefix=0;
        flag=false;
    }
};
Trie T[1000005][10];
bool insert_word(int node,string s,int ind,int sz,int prev) {
    if(ind==sz) {
        if(T[prev][s[ind-1]-48].prefix>1) return false;
        T[prev][s[ind-1]-48].flag=true;
        return true;
    }
    int k=s[ind]-48;
    if(T[node][k].num==-1) {
        T[node][k].num=++total;
    }
    if(T[node][k].flag) return false;
    T[node][k].prefix++;
    return insert_word(T[node][k].num,s,ind+1,sz,node);
}
bool search_word(int node,string s,int ind,int sz,int prev) {
    if(ind==sz) {
        return T[prev][s[ind-1]-48].flag;
    }
    int k=s[ind]-48;
    if(T[node][k].num==-1) return false;
    return search_word(T[node][k].num,s,ind+1,sz,node);
}
void clearT() {
    for(int i=0;i<1000000;i++) {
        for(int j=0;j<27;j++) {
            T[i][j].num=-1;
            T[i][j].prefix=0;
            T[i][j].flag=false;
        }
    }
}
int main()
{
    int t,n;
    string s;
    cin>>t;
    while(t--) {
        cin>>n;
        clearT();
        bool get=true;
        while(n--) {
            cin>>s;
            get=get & insert_word(0,s,0,s.length(),0);
        }
        if(get) cout<<"YES\n";
        else cout<< "NO\n";
    }
    return 0;

}
