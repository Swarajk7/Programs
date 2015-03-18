#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;
vector<int> v;
vector<int> vis;
void proc(int f) {
   int i=0,x;
   for(int i=0;i<v.size();i++) {
    //cout<<v[i]<<" ";
      x=floor(f/v[i]);
    //cout<<x<<" "<<v[i]<<endl;
      f=f-v[i]*x;
      vis[i]=x;
   }
}
void print(double x,int y) {
   if(x<100) printf("%0.2lf",x/100);
   else printf("%d",(int)(x/100));
   cout<<" "<<y<<endl;
}
int main()
{
   int t,m,n;
   cin>>t;
   int fff=t;
   while(t-->0) {
      cout<<"Case "<<fff-t<<":\n";
      v.clear();
      cin>>n>>m;
      int xx=n;
      while(xx-->0) {
        double f;
         cin>>f;
         v.push_back((int)(f*100));
         //cout<<v[v.size()-1]<<endl;
         vis.push_back(0);
      }
      sort(v.begin(),v.end());
      reverse(v.begin(),v.end());
      int ffm=m;
      while(m-->0) {
          float f;
         cin>>f;
         proc((int)(f*100));
         cout<<"Scenario "<<ffm-m<<":\n";
         for(int i=0;i<v.size();i++) {
            if(vis[i]!=0)
               print(v[i],vis[i]);
         }
      }
   }
   return 0;
}
