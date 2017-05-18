#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int total = 0;

struct Trie {
       int num;
       int prefixes;
          bool flag;
       Trie() {
              flag = false;
              prefixes = 0;
              num = -1;
       }
}T[100005][27];

void insert_word(int pos, string s, int idx, int sz, int prev) 
{
	cout<<idx<<"pos= "<<pos<<"prev= "<<prev<<endl;
     if ( idx == sz ) {
          T[prev][s[sz-1]-64].flag = true;
          return;
     }
     int val = s[idx]-64;
     if ( T[pos][val].num == -1 ) {
        total++;
        T[pos][val].num = total;
     }
     T[pos][val].prefixes++;
     insert_word(T[pos][val].num, s, idx+1, sz, pos);
}

bool search_word(int pos, string s, int idx, int sz, int prev)
{
     if ( idx == sz ) return T[prev][s[sz-1]-64].flag;
     int val = s[idx]-64;
     if ( T[pos][val].num == -1 ) return false;
     return search_word(T[pos][val].num, s, idx+1, sz, pos);
}

int prefix_cnt(int pos, string s, int idx, int sz, int prev)
{
    if ( idx == sz ) {
       return T[prev][s[sz-1]-64].prefixes;
    }
    int val = s[idx]-64;
    if ( T[pos][val].num == -1 ) return 0;
    return prefix_cnt(T[pos][val].num, s, idx+1, sz, pos);
}

void del_word(int pos, string s, int idx, int sz, int prev)
{
    if ( idx == sz ) {
         T[prev][s[sz-1]-64].flag = false;
         return;
    }
    int val = s[idx]-64;
    T[pos][val].prefixes--;
    del_word(T[pos][val].num, s, idx+1, sz, pos);
}

int main()
{
    int n,sz,m;
    string s;
    //Insert N words
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> s;
        sz = (int)s.size();
        insert_word(0,s,0,sz, 0);
    }
    // Search M words
    cin >> m;
    for ( int i = 0; i < m; i++ ) {
        cin >> s;
        sz = (int)s.size();
        if ( search_word(0, s, 0, sz, 0) ) cout << "Present" << endl;
        else cout << "Absent" << endl;
    } 
    // Count number of words having given prefix. (M queries)
    cin >> m;
    for ( int i = 0; i < m; i++ ) {
        cin >> s;
        sz = (int)s.size();
        cout << "Total prefixes = " << prefix_cnt(0, s, 0, sz, 0) << endl;
    }
    // Delete M words
    cin >> m;
    for ( int i = 0; i < m; i++ ) {
        cin >> s;
        sz = (int)s.size();
        if ( search_word(0, s, 0, sz, 0) ) del_word(0, s, 0, sz, 0);
    }
    cin >> m;
    for ( int i = 0; i < m; i++ ) {
        cin >> s;
        sz = (int)s.size();
        cout << "Total prefixes = " << prefix_cnt(0, s, 0, sz, 0) << endl;
    }
    return 0;
}
