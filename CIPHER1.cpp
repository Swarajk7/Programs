#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
bool comp(pair<char,int> a,pair<char,int> b)
{
    if(a.second!=b.second)
    return a.second<b.second;
    else return a.first<b.first;
}
char searchc(char c,vector< pair<char,int> > v);
int main()
{
    int t;
    cin>>t;
    string s;
    cin.ignore();
    while(t--)
    {
        int hsh[28]={0};
        getline(cin,s);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ') hsh[26]++;
            else if(s[i]=='.') hsh[27]++;
            else hsh[s[i]-65]++;
        }
        vector< pair<char,int> > v;
        for(int i=0;i<26;i++)
        {
            if(hsh[i]!=0)
            v.push_back(make_pair(65+i,hsh[i]));
        }
        if(hsh[26]!=0) v.push_back(make_pair(' ',hsh[26]));
        if(hsh[27]!=0) v.push_back(make_pair('.',hsh[27]));
        sort(v.begin(),v.end(),comp);
        //for(int i=0;i<v.size();i++) printf("%c %d\n", v[i].first,v[i].second);
        for(int i=0;i<s.length();i++)
        {
            s[i]=searchc(s[i],v);
        }
        cout<<s<<endl;
    }
    return 0;
}
char searchc(char c,vector< pair<char,int> > v)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i].first==c) return v[v.size()-i-1].first;
    }
}
