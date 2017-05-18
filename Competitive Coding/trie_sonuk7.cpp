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
Trie T[1000000][27];
void insert_word(int node,string s,int ind,int sz,int prev) {
    if(ind==sz) {
        T[prev][s[ind-1]-48].flag=true;
        return;
    }
    int k=s[ind]-48;
    if(T[node][k].num==-1) {
        T[node][k].num=++total;
    }
    T[node][k].prefix++;
    insert_word(T[node][k].num,s,ind+1,sz,node);
}
bool search_word(int node,string s,int ind,int sz,int prev) {
    if(ind==sz) {
        return T[prev][s[ind-1]-48].flag;
    }
    int k=s[ind]-48;
    if(T[node][k].num==-1) return false;
    return search_word(T[node][k].num,s,ind+1,sz,node);
}
int main()
{
    string s;
    s="abc";
    insert_word(0,s,0,s.length(),0);
    s="abd";insert_word(0,s,0,s.length(),0);
    cout<<search_word(0,"kbc",0,s.length(),0);
    return 0;

}
