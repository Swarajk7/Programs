#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > v;
vector< pair<int,int> > ans;
void dfs(int s) {
    if(v[s].size()==0) return;
    else {
        ans.push_back(make_pair(s,v[s][0]));
        dfs(v[s][0]);
    }
}
int main()
{
    int t,n;
    string s1,s2;
    scanf("%d",&t);
    for(int t1=1;t1<=t;t1++)
    {
        map<string,int> mp;
        map<int,string> mp2;
        v.clear();
        int cnt=0;
        scanf("%d",&n);
        v.resize(2*n);
        vector<int> ind(2*n,0);
        for(int i=0;i<n;i++) {
            int x,y;
            cin>>s1>>s2;
            if(mp.find(s1)==mp.end()) {
                x=cnt++;
                mp[s1]=x;
                mp2[x]=s1;
            }
            else x=mp[s1];
            if(mp.find(s2)==mp.end()) {
                y=cnt++;
                mp[s2]=y;
                mp2[y]=s2;
            }
            else y=mp[s2];
            v[x].push_back(y);
            ind[y]++;
        }
        int start;
        for(int i=0;i<cnt;i++) {
            if(ind[i]==0) start=i;
        }
        ans.clear();
        dfs(start);
        //cout<<"Case #"<<t1<<": ";
        for(int i=0;i<ans.size();i++) {
            pair<int,int> p=ans[i];
            //cout<<p.first<<" "<<p.second<<endl;
            s1=mp2[p.first];
            s2=mp2[p.second];
            cout<<s1<<"-"<<s2<<" ";
        }
        cout<<endl;
    }
    return 0;
}
