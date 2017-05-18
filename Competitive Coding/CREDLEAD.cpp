#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<string>
using namespace std;
int main() {
    int n;
    string s;
    std::ios::sync_with_stdio(false);
    cin>>n;
    vector<string> v(n+1,"#");
    map<string,int> m;
    for(int t=0;t<n;t++) {
        cin>>s;
        if(m.find(s)!=m.end()) {
            m[s]+=1;
            if(v[m[s]]=="#") v[m[s]]=s;
        } else {
            m[s]=1;
            if(v[m[s]]=="#") v[m[s]]=s;
        }
    }
    for(int i=1;i<n;i++) {
        if(v[i]=="#") break;
        cout<<i<<" "<<v[i]<<endl;
    }
    return 0;
}
